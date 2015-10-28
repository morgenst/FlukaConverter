#include <iostream>
#include <string>
#include <PredefinedConverters.h>
//#include <tchar.h>

#include "PredefinedConverters.h"
#include "boost/program_options.hpp"

#ifdef _MSC_VER
#include "MainFrame.h"
#endif
using namespace std;
namespace po = boost::program_options;

#ifndef _MSC_VER
int main(int argc, const char** argv) {
    po::options_description parser("FlukaConverter converts FLUKA RESNUCLei ASCII output to Excel xml format.");
    parser.add_options()
            ("infile,i", po::value<string>()->required(), "input file")
            ("outfile,o", po::value<string>()->required(), "output file")
            ("help,h", "print help message")
            ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, parser), vm);
    if (vm.count("help")) {
        cout << parser << "\n";
        return 0;
    }
    FConverter::ResnucTabExcelConverter converter(vm["infile"].as<string>(),
                                                  vm["outfile"].as<string>());
    converter.convert();

    return 0;
}
#else
int _tmain(int argc, char* argv[])
{
	FlukaConverter::MainFrame form;
	form.ShowDialog();
	return 0;
}
#endif