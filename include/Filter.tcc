//
// Created by morgenst on 12/1/15.
//

#ifndef FLUKACONVERTER_FILTER_TCC
#define FLUKACONVERTER_FILTER_TCC

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include "Filter.h"

namespace FConverter {
    using namespace std;
    template<class Type>
    typename ZeroActivityFilter<Type>::InputType ZeroActivityFilter<Type>::apply(ZeroActivityFilter<Type>::InputType&& data){
        cerr << "Not implemented" << endl;
        data.erase(remove_copy_if(data.begin(),
                                  data.end(),
                                  data.begin(),
                                  [](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) == 0.;}),
                   data.end());
        return data;
    }
}
#endif //FLUKACONVERTER_FILTER_TCC
