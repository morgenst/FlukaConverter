//
// Created by morgenst on 18/09/15.
//

#include <iostream>
#include <regex>

#include "WriterPolicy.h"
#include "Utils.h"

namespace FConverter{

    using namespace std;
    void WriterPolicy::open(const std::string &fOutput) {
        m_fOutput.open(fOutput.c_str());
    }

    string WriterPolicy::guessType(const Value& val) {
        if (std::regex_match(val, rFloat))
            return "Number";
        return "String";
    }


    void ExcelWriterPolicy::invoke(const std::string& fOutput, const ExcelWriterPolicy::DataCollection & data) {
        open(fOutput);
        writeDocHeader();

        for (const auto &dataElement : data)
            addNewSheet(move(dataElement));
        m_fOutput << "</Workbook>";
        m_fOutput.close();
    }

    void ExcelWriterPolicy::addCell(const Value& value){
        m_fOutput << "<Cell> ";
        auto type = guessType(value);
        m_fOutput << "<Data ss:Type=\"" << type << "\">" << value << "</Data> ";
        m_fOutput << "</Cell> \n";
    }

    void ExcelWriterPolicy::addRow(const Data& data) {
        m_fOutput << "<Row> \n";
        for (const auto &value : data)
            addCell(move(value));
        m_fOutput << "</Row> \n";
    }

    void ExcelWriterPolicy::addNewSheet(const DataElement& sheetInfo){
        m_fOutput << "<Worksheet ss:Name=\"" << sheetInfo.first->getVal() << "\">";
        auto nRow = 5000;sheetInfo.second.size();
        auto nColumn = Utils::getMaxSize(&sheetInfo.second);
        m_fOutput << "<Table ss:ExpandedColumnCount=\"" << nColumn << "\" ss:ExpandedRowCount=\"" << nRow << "\" \n \
        x:FullColumns=\"1\" x:FullRows=\"1\"> \n";
        for(const auto& data: sheetInfo.second)
            addRow(move(data));
        m_fOutput << "</Table> \n \
        <WorksheetOptions xmlns=\"urn:schemas-microsoft-com:office:excel\"> \n \
        <Print> \n \
        <ValidPrinterInfo /> \n \
        <HorizontalResolution>600</HorizontalResolution> \n \
        <VerticalResolution>600</VerticalResolution> \n \
        </Print> \n \
        <Selected /> \n \
        <Panes> \n \
        <Pane> \n \
        <Number>3</Number> \n \
        <ActiveRow>5</ActiveRow> \n \
        <ActiveCol>1</ActiveCol> \n \
        </Pane> \n \
        </Panes> \n \
        <Table> \n \
        </Table> \n \
        <ProtectObjects>False</ProtectObjects> \n \
        <ProtectScenarios>False</ProtectScenarios> \n \
        </WorksheetOptions> \n \
        </Worksheet> \n";

    }
    void ExcelWriterPolicy::writeDocHeader() {
        m_fOutput << "<?xml version=\"1.0\"?>\n \
        <?mso-application progid=\"Excel.Sheet\"?> \n \
        <Workbook \n \
        xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\" \n \
        xmlns:o=\"urn:schemas-microsoft-com:office:office\" \n \
        xmlns:x=\"urn:schemas-microsoft-com:office:excel\" \n \
        xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\" \n \
        xmlns:html=\"http://www.w3.org/TR/REC-html40\"> \n \
        <DocumentProperties xmlns=\"urn:schemas-microsoft-com:office:office\"> \n \
        <Author>Self</Author> \n \
        <LastAuthor>Self</LastAuthor> \n \
        <Created>2012-03-15T23:04:04Z</Created> \n \
        <Company>CERN</Company> \n \
        <Version>11.8036</Version> \n \
        </DocumentProperties> \n \
        <ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\"> \n \
        <WindowHeight>6795</WindowHeight> \n \
        <WindowWidth>8460</WindowWidth> \n \
        <WindowTopX>120</WindowTopX> \n \
        <WindowTopY>15</WindowTopY> \n \
        <ProtectStructure>False</ProtectStructure> \n \
        <ProtectWindows>False</ProtectWindows> \n \
        </ExcelWorkbook> \n \
        <Styles> \n \
        <Style ss:ID=\"Default\" ss:Name=\"Normal\"> \n \
        <Alignment ss:Vertical=\"Bottom\" /> \n \
        <Borders /> \n \
        <Font /> \n \
        <Interior /> \n \
        <NumberFormat /> \n \
        <Protection /> \n \
        </Style> \n \
        <Style ss:ID=\"s21\"> \n \
        <Font x:Family=\"Swiss\" ss:Bold=\"1\" /> \n \
        </Style> \n \
        </Styles>\n";
    }
}