//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_H
#define FLUKACONVERTER_CONVERTER_H

#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <bits/unique_ptr.h>
#include "Exceptions.h"
#include "ParsedElement.h"

namespace FConverter{
    template <typename ReadPolicy, typename WritePolicy>
    class Converter : private ReadPolicy, private WritePolicy{
        using DataElement = std::pair<std::unique_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        using Data = std::map<std::unique_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        using ReadPolicy::parse;
        using WritePolicy::invoke;

    public:
        Converter() = delete;
        Converter(const std::string& fInput);
        constexpr Converter(const Converter&) = delete;
        constexpr Converter& operator=(const Converter&) = delete;
        ~Converter();

        void convert();
    private:
        void open() throw(InvalidInput);
        void close() noexcept ;
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
