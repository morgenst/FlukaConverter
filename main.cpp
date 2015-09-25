#include <iostream>
#include <string>
#include <PredefinedConverters.h>
#include <tchar.h>

#include "PredefinedConverters.h"
#include "boost/program_options.hpp"
#ifdef _MSC_VER
#include "GUI.h"
#endif
using namespace std;
namespace po = boost::program_options;

//TODO: implement help
#ifndef _MSC_VER
int main(int argc, const char** argv) {
	
	po::options_description parser("Help");
	parser.add_options()
	("infile,i", po::value<string>(), "input file")
	("outfile,o", po::value<string>(), "output file")
	("help,h", "print help message")
	;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, parser), vm);
	cout << "input file: " << vm["infile"].as<string>() << " outputfile: " << vm["outfile"].as<string>() << endl;
	FConverter::ResnucTabExcelConverter converter(vm["infile"].as<string>(),
	vm["outfile"].as<string>());
	converter.convert();
	
    return 0;
}
#else
int _tmain(int argc, char* argv[])
{
	FlukaConverter::MyForm form;
	form.ShowDialog();
	return 0;
}
#endif