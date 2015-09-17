//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_H
#define FLUKACONVERTER_CONVERTER_H

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "ParsedElement.h"

namespace FConverter{
    template <typename ReadPolicy, typename WritePolicy>
    class Converter{
        using Data = std::map<HeaderElement, std::vector<RowElement>>;
        using ReadPolicy::parse;

    public:
        Converter() = delete;
        Converter(const std::string& fInput);
        constexpr Converter(const Converter&) = delete;
        constexpr Converter& operator=(const Converter&) = delete;
        ~Converter();

        void convert();
    private:
        void open() throw(InvalidInput);
        void read() throw(InvalidInput);
        void write();
        std::string m_fInput;
        std::string m_fOutput;
        Data m_data;
        std::ifstream m_stream;
    };
}
#include "Converter.tcc"

#endif //FLUKACONVERTER_CONVERTER_H
