//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_READER_H
#define FLUKACONVERTER_READER_H

#include <memory>
#include <string>
#include <regex>
#include "ParsedElement.h"

namespace FConverter {
    class ReaderPolicy {
    public:
        //ReaderPolicy() = delete;
        virtual std::shared_ptr<ParsedElement> parse(std::string&&) = 0;

    protected:
        ReaderPolicy(const std::string& reRow) : m_reRow(reRow) { }
        std::regex m_reRow;
        std::regex m_reHeader;

    private:
    };

    class ResnucTabReaderPolicy : public ReaderPolicy {
    public:
        ResnucTabReaderPolicy() : ReaderPolicy("^\\s*[0-9]{1,3}\\s*[0-9]{1,3}\\s*([0-9]{0,1}\\s*)[0-9]*.[0-9]*(E(\\+|\\-)[0-9]{2,3}){0,1}\\s*[0-9]*.[0-9]*\\.[0-9]*(E(\\+|\\-)[0-9]{2,3}){0,1}\\s*"){}
        std::shared_ptr<ParsedElement> parse(std::string&&) override ;
    };
}
#endif //FLUKACONVERTER_READER_H
