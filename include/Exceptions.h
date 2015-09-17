//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_EXCEPTIONS_H
#define FLUKACONVERTER_EXCEPTIONS_H

#include <exception>

namespace FConverter{
    class InvalidInput : public std::exception{
    public:
        virtual const char* what() const noexcept {
            return "Invalid input";
        }
    };
}
#endif //FLUKACONVERTER_EXCEPTIONS_H
