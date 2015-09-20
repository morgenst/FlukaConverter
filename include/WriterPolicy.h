//
// Created by morgenst on 18/09/15.
//

#ifndef FLUKACONVERTER_WRITERPOLICY_H
#define FLUKACONVERTER_WRITERPOLICY_H

#include <fstream>
#include <memory>
#include <string>
#include <map>
#include <vector>

#include "ParsedElement.h"

namespace FConverter{
    class WriterPolicy{
    protected:
        using DataCollection = std::map<std::shared_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        using DataElement = std::pair<const std::shared_ptr<HeaderElement>, std::vector<std::vector<std::string>>>;
        std::ofstream m_fOutput;
        void open(const std::string&);
    public:
        virtual void invoke(const std::string&, const DataCollection &) = 0;

    };

    class ExcelWriterPolicy : public WriterPolicy{
    public:
        ExcelWriterPolicy() {}
        void invoke(const std::string&, const DataCollection & ) override;
    private:
        void writeDocHeader();
        void addNewSheet(const DataElement&);
    };
}
#endif //FLUKACONVERTER_WRITERPOLICY_H
