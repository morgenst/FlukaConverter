//
// Created by morgenst on 17/09/15.
//

#include <iostream>
#include <utility>
#include "boost/algorithm/string/trim.hpp"
#include "boost/algorithm/string/predicate.hpp"
#include "ReaderPolicy.h"

namespace FConverter{
    using namespace std;
    using namespace boost;
    ParsedData ResnucTabReaderPolicy::parse(unique_ptr<FileContent>&& fileContent) {
        auto parsedData = ParsedData{};
        auto currentDetector = parsedData.begin();
        while(!fileContent->empty()) {
            auto line = fileContent->front();
            fileContent->pop();
            if (starts_with(line, "#"))
                continue;
            else if (regex_match(line, m_reRow)) {
                currentDetector->second->push(std::move(make_shared<RowElement>(std::move(line))));
                continue;
            }
            currentDetector = (parsedData.emplace(make_shared<HeaderElement>(std::move(line)), make_shared<SingleParsedElement>())).first;
        }
        return std::move(parsedData);
    }

    ParsedData ResnucSumReaderPolicy::parse(unique_ptr<FileContent>&& fileContent){
        
    }
}