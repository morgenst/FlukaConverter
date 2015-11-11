//
// Created by morgenst on 18/09/15.
//

#ifndef FLUKACONVERTER_UTILS_H
#define FLUKACONVERTER_UTILS_H

#include <algorithm>
#include <memory>
#include <vector>

namespace Utils{
    template<typename CastRes, typename CastSrc>
    std::unique_ptr<CastRes> static_cast_ptr(std::unique_ptr<CastSrc>& ptr){
        return std::unique_ptr<CastRes>(static_cast<CastRes*>(ptr.release()));
    };

    template<typename CastRes, typename CastSrc>
    std::unique_ptr<CastRes> static_cast_ptr(std::unique_ptr<CastSrc>&& ptr){
        return std::unique_ptr<CastRes>(static_cast<CastRes*>(ptr.release()));
    };

    template<typename VecType>
    auto getMaxSize(const std::vector<std::vector<VecType>>* const vec){
        if(vec->size() == 0)
            return static_cast<decltype(vec->front().size())> (0);
        std::vector<decltype(vec->front().size())> vecTmp(vec->size());
        std::transform(vec->begin(), vec->end(), vecTmp.begin(), std::mem_fun_ref(&std::vector<VecType>::size));
        return *(std::max_element(vecTmp.begin(), vecTmp.end()));
    }

    /*
    template<class T>
    decltype(auto) range(T end){
        static_assert(std::is_integral<T>::value,
                      "range only accepts integral values");
        return {static_cast<T>(0), end};
    }
     */
}
#endif //FLUKACONVERTER_UTILS_H
