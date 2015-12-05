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
    void ZeroActivityFilter<Type>::apply(ZeroActivityFilter<Type>::InputType* data){
        cerr << "Not implemented" << endl;
    }
}
#endif //FLUKACONVERTER_FILTER_TCC
