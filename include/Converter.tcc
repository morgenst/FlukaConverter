//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_TCC
#define FLUKACONVERTER_CONVERTER_TCC

#include <iostream>
#include <memory>

#include "boost/algorithm/string.hpp"
#include "boost/filesystem.hpp"
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "Utils.h"

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
        catch(InvalidInput& e){
            exit(1);
        }
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

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::read() throw(InvalidInput) {
        try {
            open();
        }
        catch (InvalidInput &e) {
            cerr << e.what() << endl;
            throw e;
        }
        string line;
        Data::iterator currentHeader;
        while(getline(m_stream, line)) {
            auto element = parse(move(line));
            if(element->getType() == ParsedType::skip)
                continue;

            else if (element->getType() == ParsedType::header) {
                auto headerPtr = dynamic_pointer_cast<HeaderElement>(element);
                currentHeader = m_data.find(headerPtr);
                if (currentHeader != m_data.end())
                    cerr << "Table already in parsed input" << endl;
                m_data[headerPtr] = vector<vector<string>>{};
                currentHeader = m_data.find(headerPtr);
            }

            else if(element->getType() == ParsedType::row){
                vector<string> res;
                split(res, line, is_any_of("\t "), token_compress_on);
                currentHeader->second.emplace_back(move(res));
            }
        }
        close();
    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::write() {
        invoke(m_fOutput, move(m_data));
    }
}
#endif //FLUKACONVERTER_CONVERTER_TCC
