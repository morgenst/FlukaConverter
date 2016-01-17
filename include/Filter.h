//
// Created by morgenst on 10/19/15.
//

#ifndef FLUKACONVERTER_FILTER_H
#define FLUKACONVERTER_FILTER_H

#include <string>
#include <vector>

namespace FConverter {
    class ActivityFilter{
        using InputType = std::vector<std::vector<std::string>>;
        public:
            ActivityFilter(const double& threshold) : m_dThreshold(threshold){}
            void apply(InputType*);

        private:
        double m_dThreshold;
    };
}
#endif //FLUKACONVERTER_FILTER_H
