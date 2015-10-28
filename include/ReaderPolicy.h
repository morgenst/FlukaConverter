//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_READER_H
#define FLUKACONVERTER_READER_H

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
    };
}
#endif //FLUKACONVERTER_READER_H
