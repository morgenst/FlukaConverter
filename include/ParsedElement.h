//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_PARSEDELEMENT_H
#define FLUKACONVERTER_PARSEDELEMENT_H

enum class ParsedType {header, row, skip};

namespace FConverter{
    class ParsedElement{
    public:
        virtual ParsedType  getType() noexcept = 0;
    private:
        ParsedType m_parsedType;
    };

    class HeaderElement : public ParsedElement{
    public:
        inline ParsedType getType() noexcept override { return ParsedType::header; }
    };

    class RowElement : public ParsedElement{
    public:
        inline ParsedType getType() noexcept override { return ParsedType::row; }
    };

    class SkipElement : public ParsedElement{
    public:
        inline ParsedType getType() noexcept override { return ParsedType::skip; }
    };
}

#endif //FLUKACONVERTER_PARSEDELEMENT_H
