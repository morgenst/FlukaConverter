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
        using Data = std::vector<std::string>;
        using Value = std::string;

    public:
        virtual void invoke(const std::string&, const DataCollection &) = 0;

    protected:
        std::string guessType(const Value&);
        void open(const std::string&);
        std::ofstream m_fOutput;

    private:
        const std::regex rFloat {"[0-9]*\\.?[0-9]*([Ee][+-]?[0-9]+)?"};
    };

    class ExcelWriterPolicy : public WriterPolicy{
    public:
        ExcelWriterPolicy() {}
        void invoke(const std::string&, const DataCollection & ) override;
    private:
        void writeDocHeader();
        void addNewSheet(const DataElement&);
        void addRow(const Data& data);
        void addCell(const Value& value);
    };
}
#endif //FLUKACONVERTER_WRITERPOLICY_H
