//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_PARSEDELEMENT_H
#define FLUKACONVERTER_PARSEDELEMENT_H

#include "boost/algorithm/string/trim.hpp"
enum class ParsedType {header, row, skip};

namespace FConverter{
    class ParsedElement{
    public:
        virtual ParsedType getType() noexcept = 0;
        virtual std::string getVal() const noexcept = 0;

    protected:
        std::string m_val;
    };

    class HeaderElement : public ParsedElement{
    public:
        HeaderElement() = delete;
        HeaderElement(std::string&& val){ boost::trim(val); m_val = val; }
        inline ParsedType getType() noexcept override { return ParsedType::header; }
        std::string getVal() const noexcept override { return m_val; }
    };

    class RowElement : public ParsedElement{
    public:
        RowElement() = delete;
        RowElement(std::string&& val){ boost::trim(val); m_val = val; }
        inline ParsedType getType() noexcept override { return ParsedType::row; }
        std::string getVal() const noexcept override { return m_val; }
    };

    class SkipElement : public ParsedElement{
    public:
        SkipElement(){}
        inline ParsedType getType() noexcept override { return ParsedType::skip; }
        std::string getVal() const noexcept override { return ""; }

    };
}

#endif //FLUKACONVERTER_PARSEDELEMENT_H
