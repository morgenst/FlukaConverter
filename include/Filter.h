//
// Created by morgenst on 10/19/15.
//

#ifndef FLUKACONVERTER_FILTER_H
#define FLUKACONVERTER_FILTER_H

#include <vector>
#include "ReaderPolicy.h"

namespace FConverter {
    template<typename Type, typename ValType, unsigned int Element>
    class ThresholdFilter {
    public:
        ThresholdFilter(const ValType& threshold) : m_threshold(threshold){}
        virtual bool apply(std::vector<std::string>&&) = 0;
    protected:
        ValType m_threshold;
        bool skipElement(std::vector<std::string>&&){};
    };
/*
    template<ResnucTabReaderPolicy Type, float ValType, unsigned int Element>
    class ThresholdFilter{
        bool apply(std::vector<std::string>&&);

    };
    */
}
#endif //FLUKACONVERTER_FILTER_H
