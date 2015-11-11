//
// Created by morgenst on 17/09/15.
//

#include <iostream>
#include <utility>
#include "boost/algorithm/string/predicate.hpp"
#include "boost/algorithm/string/replace.hpp"
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/trim.hpp"
#include "ReaderPolicy.h"
#include "Utils.h"

namespace FConverter{
    using namespace std;
    using namespace boost;
    using namespace Utils;

    ParsedData ResnucTabReaderPolicy::parse(unique_ptr<FileContent>&& fileContent) {
        auto parsedData = ParsedData{};
        auto currentDetector = parsedData.begin();
        while(!fileContent->empty()) {
            auto line = fileContent->front();
            fileContent->pop();
            if (starts_with(line, "#"))
                continue;
            else if (regex_match(line, m_reRow)){
                currentDetector->second->push(std::move(make_shared<RowElement>(std::move(line))));
                continue;
            }
            currentDetector = (parsedData.emplace(make_shared<HeaderElement>(std::move(line)), make_shared<SingleParsedElement>())).first;
        }
        return std::move(parsedData);
    }

    ParsedData ResnucSumReaderPolicy::parse(unique_ptr<FileContent>&& fileContent){
        auto parsedData = ParsedData{};
        auto currentDetector = parsedData.begin();
        while(!fileContent->empty()) {
            //todo:: this can go in it's own function in Base
            auto line = fileContent->front();
            fileContent->pop();
            trim(line);
            if (line.find("Detector n:") != string::npos) {
                currentDetector = (parsedData.emplace(make_shared<HeaderElement>(std::move(line)),
                                                      make_shared<SingleParsedElement>())).first;
                continue;
            }
            if(starts_with(line,"A \\ Z")){
                readZ(std::move(line));
                while(true){
                    line = fileContent->front();
                    fileContent->pop();
                    if(line.empty())
                        break;
                    trim(line);
                    if(starts_with(line,"A \\ Z")){
                        readZ(std::move(line));
                        continue;
                    }
                    if(line.find("Isomers") != string::npos){
                        //readIsomeres();
                        break;
                    }
                    parseA(std::move(line));
                    line = fileContent->front();
                    fileContent->pop();
                    parseUncertainty(std::move(line));
                    while(!m_lZ.empty()){
                        auto tmpLine = m_iCurrentA + " " + m_lZ.front() + " " + m_lAct.front() + " " + m_lUncertainty.front();
                        currentDetector->second->push(std::move(make_shared<RowElement>(std::move(tmpLine))));
                        m_lZ.pop_front();
                        m_lAct.pop_front();
                        m_lUncertainty.pop_front();
                    }
                }
            }
        }
        return std::move(parsedData);
    }

    void ResnucSumReaderPolicy::readZ(string&& line){
        trim(line);
        m_lZ.clear();
        split(m_lZ, line, is_any_of("\t "), token_compress_on);
        m_lZ.remove_if([&](auto i) {return !(regex_match(i,std::regex("\\d+")));});
    }

    void ResnucSumReaderPolicy::parseA(string&& line){
        m_lAct.clear();
        split(m_lAct, line, is_any_of("\t "), token_compress_on);
        m_iCurrentA = m_lAct.front();
        m_lAct.pop_front();
    }

    void ResnucSumReaderPolicy::parseUncertainty(string&& line){
        m_lUncertainty.clear();
        replace_all(line, "+/-" , "");
        replace_all(line, "%" , "");
        trim(line);
        split(m_lUncertainty, line, is_any_of("\t "), token_compress_on);
    }
}
/*
 * void ResnucUncertaintyFileHandler::readIsomeres(){
    string line;
    while(getline(fStream, line)){
        if(line.empty())
            return;
        trim(line);
        if(starts_with(line, "A"))
            continue;
        std::vector<std::string> res;
        split(res, line, is_any_of("\t "), token_compress_on);
    }

    */