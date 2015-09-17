#include <iostream>
#include <string>
#include "boost/program_options.hpp"

using namespace std;
namespace po = boost::program_options;

int main(int argc, const char** argv) {
    po::options_description parser("Help");
    parser.add_options()
            ("infile,i", po::value<string>(), "input file")
            ("outfile,o", po::value<string>(), "output file")
            ("help,h", "print help message")
            ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, parser), vm);
    return 0;
}