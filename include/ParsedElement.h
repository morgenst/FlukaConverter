//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_PARSEDELEMENT_H
#define FLUKACONVERTER_PARSEDELEMENT_H

enum class ParsedType {header, row};

namespace FConverter{
    class ParsedElement{
    public:
        inline ParsedType virtual getType() noexcept ;
    private:
        ParsedType m_parsedType;
    };

    class HeaderElement : public ParsedElement{
    public:
        inline ParsedType getType() noexcept override { return ParsedType::header; };
    };

    class RowElement : public ParsedElement{
    public:
        inline ParsedType getType() noexcept override { return ParsedType::row; };
    };
}

#endif //FLUKACONVERTER_PARSEDELEMENT_H
