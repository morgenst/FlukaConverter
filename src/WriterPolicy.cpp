//
// Created by morgenst on 18/09/15.
//

#include <iostream>

#include "WriterPolicy.h"

namespace FConverter{

    using namespace std;
    void WriterPolicy::open(const std::string &fOutput) {
        m_fOutput.open(fOutput.c_str());
    }


    void ExcelWriterPolicy::invoke(const std::string& fOutput, const ExcelWriterPolicy::DataCollection & data) {
        open(fOutput);
        writeDocHeader();

        for(const auto& dataElement : data)
            addNewSheet(move(dataElement));
        m_fOutput.close();
    }

    void ExcelWriterPolicy::addNewSheet(const DataElement& sheetInfo){
        m_fOutput << "<Worksheet ss:Name=\"" << sheetInfo.first->getVal() << "\">";
        /*
                           <Table ss:ExpandedColumnCount="2" ss:ExpandedRowCount="5"
        x:FullColumns="1" x:FullRows="1">
                                     <Row>
                                     <Cell>
                                     <Data ss:Type="String">Text in cell A1</Data>
                                                                         </Cell>
                                                                           </Row>
                                                                             <Row>
                                                                             <Cell ss:StyleID="s21">
                                                                                              <Data ss:Type="String">Bold text in A2</Data>
                                                                                                                                  </Cell>
                                                                                                                                    </Row>
                                                                                                                                      <Row ss:Index="4">
                                                                                                                                                    <Cell ss:Index="2">
                                                                                                                                                                   <Data ss:Type="Number">43</Data>
                                                                                                                                                                                              </Cell>
                                                                                                                                                                                                </Row>
                                                                                                                                                                                                  <Row>
                                                                                                                                                                                                  <Cell ss:Index="2" ss:Formula="=R[-1]C/2">
                                                                                                                                                                                                                                <Data ss:Type="Number">21.5</Data>
                                                                                                                                                                                                                                                             </Cell>
                                                                                                                                                                                                                                                               </Row>
                                                                                                                                                                                                                                                                 </Table>
                                                                                                                                                                                                                                                                   <WorksheetOptions xmlns="urn:schemas-microsoft-com:office:excel">
                                                                                                                                                                                                                                                                                           <Print>
                                                                                                                                                                                                                                                                                           <ValidPrinterInfo />
                                                                                                                                                                                                                                                                                           <HorizontalResolution>600</HorizontalResolution>
                                                                                                                                                                                                                                                                                                                      <VerticalResolution>600</VerticalResolution>
                                                                                                                                                                                                                                                                                                                                               </Print>
                                                                                                                                                                                                                                                                                                                                                 <Selected />
                                                                                                                                                                                                                                                                                                                                                 <Panes>
                                                                                                                                                                                                                                                                                                                                                 <Pane>
                                                                                                                                                                                                                                                                                                                                                 <Number>3</Number>
                                                                                                                                                                                                                                                                                                                                                            <ActiveRow>5</ActiveRow>
                                                                                                                                                                                                                                                                                                                                                                          <ActiveCol>1</ActiveCol>
                                                                                                                                                                                                                                                                                                                                                                                        </Pane>
                                                                                                                                                                                                                                                                                                                                                                                          </Panes>
                                                                                                                                                                                                                                                                                                                                                                                            <Table>
                                                                                                                                                                                                                                                                                                                                                                                            </Table>
                                                                                                                                                                                                                                                                                                                                                                                              <ProtectObjects>False</ProtectObjects>
                                                                                                                                                                                                                                                                                                                                                                                              <ProtectScenarios>False</ProtectScenarios>
                                                                                                                                                                                                                                                                                                                                                                                              </WorksheetOptions>
                                                                                                                                                                                                                                                                                                                                                                                                </Worksheet>
*/
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
        \<Version>11.8036</Version> \n \
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
/*

        </Workbook>
        */