//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_TCC
#define FLUKACONVERTER_CONVERTER_TCC

#include <iostream>
#include <queue>
#include <memory>
#include <sstream>
#include <utility>

#include "boost/algorithm/string.hpp"
#include "boost/filesystem.hpp"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "Utils.h"
#include "Filter.h"
#include "ReaderPolicy.h"
#include "WriterPolicy.h"

using namespace std;
using namespace boost;

namespace FConverter {
    template<typename ReadPolicy, typename WritePolicy>
    Converter<ReadPolicy, WritePolicy>::Converter(const std::string& fInput,
                                                  const std::string& fOutput) : m_fInput(std::move(fInput)),
                                                                                m_fOutput(fOutput){ }

    template<typename ReadPolicy, typename WritePolicy>
    Converter<ReadPolicy, WritePolicy>::~Converter() { }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::convert() {
        try {
            read();
        }
        catch(InvalidInput&){
            exit(1);
        }
        applyFilters();
        write();
    }

    template <typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::open() throw(InvalidInput){
        if(!filesystem::exists(filesystem::path(m_fInput)))
            throw InvalidInput{"Input file does not exist."};
        m_stream.open(m_fInput);
        if(!m_stream.is_open())
            throw InvalidInput{};
    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::close() noexcept {
        if(m_stream.is_open())
            m_stream.close();
    }

    template <typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::transform(ParsedData&& parsedData){
        Data::iterator currentHeader;
        ActivityFilter filter(0.);
        for(auto parsedDetector : parsedData){
            auto headerPtr = parsedDetector.first;
            m_data[headerPtr] = vector<vector<string>>{};
            currentHeader = m_data.find(headerPtr);
            auto parsedElements = parsedDetector.second;
            while(!parsedElements->empty()){
                vector<string> res;
                auto tmp = parsedElements->front()->getVal();
                split(res, tmp, is_any_of("\t "), token_compress_on);
                currentHeader->second.emplace_back(std::move(res));
                parsedElements->pop();
            }
            filter.apply(&currentHeader->second);
        }
    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::read() throw(InvalidInput) {
        try {
            open();
        }
        catch (InvalidInput &e) {
            cerr << e.what() << endl;
            throw e;
        }
        auto fileContent = make_unique<queue<string>>();
        string tmpLine;
        while(getline(m_stream, tmpLine))
            fileContent->push(tmpLine);
        transform(parse(std::move(fileContent)));
        close();
    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::write() {
        invoke(m_fOutput, std::move(m_data));
    }

    template<typename ReaderPolicy, typename WriterPolicy>
    void Converter<ReaderPolicy, WriterPolicy>::applyFilters(){
        auto filterStore = FilterStore::getInstance();
        for(const auto& pFilter : *(filterStore->receive()))
            applyFilter(pFilter);
    };

    template <typename ReaderPolicy, typename WriterPolicy>
    void Converter<ReaderPolicy, WriterPolicy>::applyFilter(const std::unique_ptr<Filter>& pFilter) {
        for(auto& kv : m_data)
            pFilter->apply(&kv.second);
    }

}

#endif //FLUKACONVERTER_CONVERTER_TCC
