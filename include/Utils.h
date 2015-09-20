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
        std::vector<decltype(vec->front().size())> vecTmp(vec->size());
        std::transform(vec->begin(), vec->end(), vecTmp.begin(), std::mem_fun_ref(&std::vector<VecType>::size));
        return *(std::max_element(vecTmp.begin(), vecTmp.end()));
    }
}
#endif //FLUKACONVERTER_UTILS_H
