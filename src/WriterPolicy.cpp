//
// Created by morgenst on 18/09/15.
//

#include "WriterPolicy.h"

namespace FConverter{

    void WriterPolicy::open(const std::string &fOutput) {
        m_fOutput.open(fOutput.c_str());
    }


    void ExcelWriterPolicy::invoke(const std::string& fOutput, ExcelWriterPolicy::DataElement&& data) {

    }
}
/*
        <?xml version="1.0"?>
        <?mso-application progid="Excel.Sheet"?>
        <Workbook
        xmlns="urn:schemas-microsoft-com:office:spreadsheet"
        xmlns:o="urn:schemas-microsoft-com:office:office"
        xmlns:x="urn:schemas-microsoft-com:office:excel"
        xmlns:ss="urn:schemas-microsoft-com:office:spreadsheet"
        xmlns:html="http://www.w3.org/TR/REC-html40">
                   <DocumentProperties xmlns="urn:schemas-microsoft-com:office:office">
                                             <Author>Someone</Author>
                                             <LastAuthor>Self</LastAuthor>
                                             <Created>2012-03-15T23:04:04Z</Created>
        <Company>Eaton Corporation</Company>
        <Version>11.8036</Version>
        </DocumentProperties>
        <ExcelWorkbook xmlns="urn:schemas-microsoft-com:office:excel">
                             <WindowHeight>6795</WindowHeight>
        <WindowWidth>8460</WindowWidth>
        <WindowTopX>120</WindowTopX>
        <WindowTopY>15</WindowTopY>
        <ProtectStructure>False</ProtectStructure>
        <ProtectWindows>False</ProtectWindows>
        </ExcelWorkbook>
        <Styles>
        <Style ss:ID="Default" ss:Name="Normal">
                                       <Alignment ss:Vertical="Bottom" />
                                                              <Borders />
                                                              <Font />
                                                              <Interior />
                                                              <NumberFormat />
                                                              <Protection />
                                                              </Style>
        <Style ss:ID="s21">
                     <Font x:Family="Swiss" ss:Bold="1" />
                                                    </Style>
        </Styles>
        <Worksheet ss:Name="Sheet1">
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
        </Workbook>
        */