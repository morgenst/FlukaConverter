//
// Created by morgenst on 18/09/15.
//

#ifndef FLUKACONVERTER_UTILS_H
#define FLUKACONVERTER_UTILS_H

#include <memory>

namespace Utils{
    template<typename CastRes, typename CastSrc>
    std::unique_ptr<CastRes> static_cast_ptr(std::unique_ptr<CastSrc>& ptr){
        return std::unique_ptr<CastRes>(static_cast<CastRes*>(ptr.release()));
    };

    template<typename CastRes, typename CastSrc>
    std::unique_ptr<CastRes> static_cast_ptr(std::unique_ptr<CastSrc>&& ptr){
        return std::unique_ptr<CastRes>(static_cast<CastRes*>(ptr.release()));
    };
}
#endif //FLUKACONVERTER_UTILS_H
