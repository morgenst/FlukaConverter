//
// Created by morgenst on 10/19/15.
//

#include "Filter.h"

#include <algorithm>

using namespace std;
namespace FConverter {

    shared_ptr<FilterStore> FilterStore::m_Instance = nullptr;

    void ActivityFilter::apply(InputType* data){
        data->erase(remove_copy_if(data->begin(),
                                   data->end(),
                                   data->begin(),
                                   [this](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) <= m_dThreshold;}),
                    data->end());
    }
}