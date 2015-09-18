//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_READER_H
#define FLUKACONVERTER_READER_H

#include <string>
#include "ParsedElement.h"

namespace FConverter {
    class ReaderPolicy {
    public:
        virtual constexpr ParsedElement&& parse(const std::string) = 0;
    private:
    };

    class ResnucTabReaderPolicy : public ReaderPolicy {
    public:
        virtual ParsedElement&& parse(const std::string);
    };
}
#endif //FLUKACONVERTER_READER_H
