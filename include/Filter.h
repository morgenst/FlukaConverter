//
// Created by morgenst on 10/19/15.
//

#ifndef FLUKACONVERTER_FILTER_H
#define FLUKACONVERTER_FILTER_H

#include <vector>
#include "ReaderPolicy.h"

namespace FConverter {
    template<typename Type>
    class ZeroActivityFilter {
        using InputType = std::vector<std::vector<std::string>>;
    public:
        ZeroActivityFilter(const float& threshold) : m_threshold(threshold){}
        InputType apply(InputType &&);
    protected:
        float m_threshold;
    };
}

#include "Filter.tcc"
#endif //FLUKACONVERTER_FILTER_H
