//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_EXCEPTIONS_H
#define FLUKACONVERTER_EXCEPTIONS_H

#include <exception>

namespace FConverter{
    class InvalidInput : public std::exception{
    public:
        InvalidInput() : m_message("Invalid input"){}
        InvalidInput(const std::string& message) : m_message(message) {}
        virtual const char* what() const noexcept {
            return m_message.c_str();
        }

    private:
        std::string m_message;
    };
}
#endif //FLUKACONVERTER_EXCEPTIONS_H
