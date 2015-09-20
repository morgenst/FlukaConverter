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
    shared_ptr <ParsedElement> ResnucTabReaderPolicy::parse(string&& line) {
        if(starts_with(line, "#"))
            return std::move(shared_ptr<SkipElement>(new SkipElement));
        if(regex_match(line, m_reRow))
            return std::move(shared_ptr<RowElement>(new RowElement(move(line))));
        return std::move(shared_ptr<HeaderElement>(new HeaderElement(move(line))));
    }
}