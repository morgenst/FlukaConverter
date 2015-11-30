#include <iostream>
#include "boost/program_options.hpp"
#include "PredefinedConverters.h"

#ifdef _MSC_VER
#include "MainFrame.h"
#endif
using namespace std;
namespace po = boost::program_options;

#ifndef _MSC_VER
int main(int argc, char** argv) {
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
    string fInput;
    try {
        fInput = vm["infile"].as<string>();
    }
    catch(boost::exception const& ex){
        cout << "Input file does not exist.";
        return EXIT_FAILURE;
    }
    if(boost::ends_with(fInput, "_tab.lis")) {
        FConverter::ResnucTabExcelConverter converter(fInput,
                                                      vm["outfile"].as<string>());
        converter.convert();
    }
    else if(boost::ends_with(fInput, "_sum.lis")) {
        FConverter::ResnucSumExcelConverter converter(fInput,
                                                      vm["outfile"].as<string>());
        converter.convert();
    }
    else
        cerr << "Unable to find predefined converter" << endl;

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