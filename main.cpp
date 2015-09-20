#include <iostream>
#include <string>
#include <PredefinedConverters.h>

#include "PredefinedConverters.h"
#include "boost/program_options.hpp"

using namespace std;
namespace po = boost::program_options;

//TODO: implement help
int main(int argc, const char** argv) {
    po::options_description parser("Help");
    parser.add_options()
            ("infile,i", po::value<string>(), "input file")
            ("outfile,o", po::value<string>(), "output file")
            ("help,h", "print help message")
            ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, parser), vm);
    FConverter::ResnucTabExcelConverter converter(vm["infile"].as<string>(),
                                                  vm["outfile"].as<string>());
    converter.convert();

    return 0;
}