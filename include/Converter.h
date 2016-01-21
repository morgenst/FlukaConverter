//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_H
#define FLUKACONVERTER_CONVERTER_H

#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <fstream>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "Filter.h"
#include "ParsedElement.h"

namespace FConverter{
    template <typename ReadPolicy, typename WritePolicy>
    class Converter : private ReadPolicy, private WritePolicy{
        using SingleParsedElement = std::queue<std::shared_ptr<ParsedElement>>;
        using ParsedElements = std::shared_ptr<SingleParsedElement>;
        using ParsedData = std::map<std::shared_ptr<HeaderElement>, ParsedElements>;
        using DataElement = std::pair<std::shared_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        using Data = std::map<std::shared_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        using ReadPolicy::parse;
        using WritePolicy::invoke;

    public:
        Converter() = delete;
        Converter(const std::string& fInput, const std::string& fOutput);
        constexpr Converter(const Converter&) = delete;
		#ifdef _MSC_VER
		Converter& operator=(const Converter&) = delete;
		#else
        constexpr Converter& operator=(const Converter&) = delete;
		#endif
        ~Converter();

        void convert();
    private:
        void open() throw(InvalidInput);
        void close() noexcept ;
        void read() throw(InvalidInput);
        void write();
        void transform(ParsedData&&);
		void applyFilters();
        void applyFilter(const std::unique_ptr<Filter>& pFilter);
        std::string m_fInput;
        std::string m_fOutput;
        Data m_data;
        std::ifstream m_stream;
    };
}

#include "Converter.tcc"

#endif //FLUKACONVERTER_CONVERTER_H
