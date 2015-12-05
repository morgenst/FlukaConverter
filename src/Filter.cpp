//
// Created by morgenst on 10/19/15.
//

#include "Filter.h"

using namespace std;
namespace FConverter {
    template <>
    void ZeroActivityFilter<ResnucTabReaderPolicy>::apply(ZeroActivityFilter<ResnucTabReaderPolicy>::InputType* data){
        data->erase(remove_copy_if(data->begin(),
                                   data->end(),
                                   data->begin(),
                                   [this](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) == m_threshold;}),
                    data->end());
    }

    template <>
    void ZeroActivityFilter<ResnucSumReaderPolicy>::apply(ZeroActivityFilter<ResnucSumReaderPolicy>::InputType* data){
        data->erase(remove_copy_if(data->begin(),
                                   data->end(),
                                   data->begin(),
                                   [this](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) == m_threshold;}),
                    data->end());
    }
}