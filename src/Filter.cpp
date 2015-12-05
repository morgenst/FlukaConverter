//
// Created by morgenst on 10/19/15.
//

#include "Filter.h"

using namespace std;
namespace FConverter {
    template <>
    ZeroActivityFilter<ResnucTabReaderPolicy>::InputType ZeroActivityFilter<ResnucTabReaderPolicy>::apply(ZeroActivityFilter<ResnucTabReaderPolicy>::InputType&& data){
        data.erase(remove_copy_if(data.begin(),
                                  data.end(),
                                  data.begin(),
                                  [](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) == 0.;}),
                   data.end());
        return data;
    }

    template <>
    ZeroActivityFilter<ResnucSumReaderPolicy>::InputType ZeroActivityFilter<ResnucSumReaderPolicy>::apply(ZeroActivityFilter<ResnucSumReaderPolicy>::InputType&& data){
        data.erase(remove_copy_if(data.begin(),
                                  data.end(),
                                  data.begin(),
                                  [](auto elem) -> bool{return atof(elem.rbegin()[1].c_str()) == 0.;}),
                   data.end());
        return data;
    }
}