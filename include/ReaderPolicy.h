//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_READER_H
#define FLUKACONVERTER_READER_H

#include <forward_list>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <regex>
#include "ParsedElement.h"

namespace FConverter {
    using FileContent = std::queue<std::string>;
    using SingleParsedElement = std::queue<std::shared_ptr<ParsedElement>>;
    using ParsedElements = std::shared_ptr<SingleParsedElement>;
    using ParsedData = std::map<std::shared_ptr<HeaderElement>, ParsedElements>;
    using ParsedDataElement = decltype(ParsedData().begin());

    class ReaderPolicy {
    public:
        //ReaderPolicy() = delete;
        virtual ParsedData parse(std::unique_ptr<FileContent>&&) = 0;

    protected:
        ReaderPolicy(const std::string& reRow) : m_reRow(reRow) { }
        std::regex m_reRow;
        std::regex m_reHeader;
    };

    class ResnucTabReaderPolicy : public ReaderPolicy {
    public:
        ResnucTabReaderPolicy() : ReaderPolicy("^\\s*[0-9]{1,3}\\s*[0-9]{1,3}\\s*([0-9]{0,1}\\s*)[0-9]*.[0-9]*(E(\\+|\\-)[0-9]{2,3}){0,1}\\s*[0-9]*.[0-9]*\\.[0-9]*(E(\\+|\\-)[0-9]{2,3}){0,1}\\s*"){}
        ParsedData parse(std::unique_ptr<FileContent>&&) override;
    };

    class ResnucSumReaderPolicy : public ReaderPolicy{
    public:
        ResnucSumReaderPolicy() : ReaderPolicy(""){}
        ParsedData parse(std::unique_ptr<FileContent>&&) override;

    private:
        void readZ(std::string&& );
        void parseA(std::string&& );
        void parseUncertainty(std::string&& );
        void parseIsomeres();
        void parseDetector(ParsedData& parsedData);
        void addRow();
        std::string m_iCurrentA;
        std::forward_list<std::string> m_lZ;
        std::forward_list<std::string> m_lAct;
        std::forward_list<std::string> m_lUncertainty;
        std::unique_ptr<FileContent> m_pFileContent;
        ParsedDataElement m_CurrentDetector;
    };
}
#endif //FLUKACONVERTER_READER_H
