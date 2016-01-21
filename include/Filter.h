//
// Created by morgenst on 10/19/15.
//

#ifndef FLUKACONVERTER_FILTER_H
#define FLUKACONVERTER_FILTER_H

#include <memory>
#include <string>
#include <vector>

namespace FConverter {

    class Filter;
    class FilterStore{
    public:
        using storedType = std::unique_ptr<Filter>;
        static std::shared_ptr<FilterStore> getInstance(){
            if(!m_Instance) {
                //need helper as make_shared requires new
                struct make_shared_enabler : public FilterStore{ };
                m_Instance = std::make_shared<make_shared_enabler>();
            }
            return m_Instance;
        };
        inline void registerFilter(storedType&& pFilter){ m_vStoredFilters->emplace_back(std::move(pFilter)); }
        inline auto receive() const { return m_vStoredFilters; }
    private:
        FilterStore() :m_vStoredFilters(std::make_shared<std::vector<storedType>>()){}
        ~FilterStore() = default;
        static std::shared_ptr<FilterStore> m_Instance;
        std::shared_ptr<std::vector<storedType> > m_vStoredFilters;

    };

    class Filter{
    public:
        using InputType = std::vector<std::vector<std::string>>;
        Filter(const double& threshold) : m_dThreshold(threshold){};
        ~Filter() = default;
        virtual void apply(InputType*) = 0;

    protected:
        double m_dThreshold;
    };

    class ActivityFilter : public Filter{

        public:
            ActivityFilter(const double& threshold) : Filter(threshold){}
            void apply(InputType*);
    };
}

#endif //FLUKACONVERTER_FILTER_H
