//
// Created by morgenst on 18/09/15.
//

#ifndef FLUKACONVERTER_WRITERPOLICY_H
#define FLUKACONVERTER_WRITERPOLICY_H

#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "ParsedElement.h"

namespace FConverter{
    class WriterPolicy{
    protected:
        using DataElement = std::pair<std::unique_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        std::ofstream m_fOutput;
        void open(const std::string&);
    public:
        virtual void invoke(const std::string&, DataElement&) = 0;

    };

    class ExcelWriterPolicy : public WriterPolicy{
    public:
        ExcelWriterPolicy() {}
        void invoke(const std::string&, DataElement& ) override;
    };
}
#endif //FLUKACONVERTER_WRITERPOLICY_H
