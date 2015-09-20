//
// Created by morgenst on 18/09/15.
//

#ifndef FLUKACONVERTER_PREDEFINEDCONVERTERS_H_H
#define FLUKACONVERTER_PREDEFINEDCONVERTERS_H_H

#include "Converter.h"
#include "ReaderPolicy.h"
#include "WriterPolicy.h"

namespace FConverter {
     class ResnucTabExcelConverter : public Converter<ResnucTabReaderPolicy, ExcelWriterPolicy>{
     public:
         ResnucTabExcelConverter(const std::string& fInput, const std::string& fOutput) : Converter(fInput, fOutput) {}
     };
}
#endif //FLUKACONVERTER_PREDEFINEDCONVERTERS_H_H
