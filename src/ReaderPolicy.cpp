//
// Created by morgenst on 17/09/15.
//

#include <iostream>
#include <utility>
#include "boost/algorithm/string/erase.hpp"
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
    using std::move;
    using std::shared_ptr;

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
        m_pFileContent = std::move(fileContent);
        auto parsedData = ParsedData{};
        m_CurrentDetector = parsedData.begin();
        while(!m_pFileContent->empty()) {
            //todo:: this can go in it's own function in Base
            auto line = m_pFileContent->front();
            trim(line);
            if (line.find("Beam intensity") != string::npos) {
                parseDetector(parsedData);
                continue;
            }
            m_pFileContent->pop();
            if(starts_with(line,"A \\ Z")){
                readZ(std::move(line));
                while(true){
                    line = m_pFileContent->front();
                    m_pFileContent->pop();
                    if(line.empty())
                        break;
                    trim(line);
                    if(starts_with(line,"A \\ Z")){
                        readZ(std::move(line));
                        continue;
                    }
                    parseA(std::move(line));
                    line = m_pFileContent->front();
                    m_pFileContent->pop();
                    parseUncertainty(std::move(line));
                    addRow();
                }
            }
            if(line.find("Isomers") != string::npos)
                parseIsomeres();
        }
        return std::move(parsedData);
    }

    void ResnucSumReaderPolicy::addRow(){
        while(!m_lZ.empty()) {
            auto tmpLine = m_iCurrentA + " " + m_lZ.front() + " " + m_lAct.front() + " " + m_lUncertainty.front();
            m_CurrentDetector->second->push(std::move(make_shared<RowElement>(std::move(tmpLine))));
            m_lZ.pop_front();
            m_lAct.pop_front();
            m_lUncertainty.pop_front();
        }
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

    void ResnucSumReaderPolicy::parseIsomeres() {
        while (true) {
            auto line = m_pFileContent->front();
            m_pFileContent->pop();
            trim(line);
            if (line.empty())
                break;
            if (starts_with(line, "A"))
                continue;
            erase_all(line, "+/-");
            erase_all(line, "%");
            m_CurrentDetector->second->push(std::move(make_shared<RowElement>(std::move(line))));
        }
    }

    void ResnucSumReaderPolicy::parseDetector(ParsedData& parsedData){
        ParsedElements detectorInfo = make_shared<SingleParsedElement>(); //queue
        shared_ptr<HeaderElement> spHeader;
        while(true){
            auto line = m_pFileContent->front();
            m_pFileContent->pop();
            trim(line);
            if(line.empty())
                continue;
            if(starts_with(line, "****"))
                break;
            if(starts_with(line, "Detector")){
                vector<string> tmp;
                split(tmp, line, is_any_of("\t "), token_compress_on);
                spHeader = make_shared<HeaderElement>(std::move(tmp.back()));
                continue;
            }
            erase_all(line, "(");
            erase_all(line, ")");
            detectorInfo->emplace(std::move(make_shared<RowElement>(std::move(line))));
        }
        m_CurrentDetector = (parsedData.emplace(move(spHeader),
                                                move(detectorInfo))).first;
    }
}