//
// Created by morgenst on 17/09/15.
//

#ifndef FLUKACONVERTER_CONVERTER_TCC
#define FLUKACONVERTER_CONVERTER_TCC

#include <iostream>

using namespace std;

namespace FConverter {
    template<typename ReadPolicy, typename WritePolicy>
    Converter<ReadPolicy, WritePolicy>::Converter(const std::string& fInput) : m_fInput(std::move(fInput)){ }

    template<typename ReadPolicy, typename WritePolicy>
    Converter<ReadPolicy, WritePolicy>::~Converter() { }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::convert() { }

    template <typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::open() throw(InvalidInput){
        m_stream.open(m_fInput);
        if(!m_stream.is_open())
            throw new InvalidInput{};
    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::read() throw(InvalidInput) {
        try {
            open();
        }
        catch (InvalidInput &e) {
            cerr << e.what() << endl;
            throw e;
        }
        string line;
        while(getline(m_stream, line)) {
            auto element = parse(line);
            if (element.getType() == ParsedType::header) {
                const auto it = m_data.find(element);
                if (it != m_data.end())
                    cerr << "Table already in parsed input" << endl;
                //continue;
            }
        }

    }

    template<typename ReadPolicy, typename WritePolicy>
    void Converter<ReadPolicy, WritePolicy>::write() { }
}
#endif //FLUKACONVERTER_CONVERTER_TCC