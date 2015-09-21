# FlukaConverter

A tool for conversion of ASCII output from Fluka to Excel, LaTeX, etc.

## Requirements

- cmake (> version 3.1)
- C++ compiler with C++14 support (clang 3.7, gcc 4.9.2)
- boost

## Installation

Checkout from git, run cmake . and enter (g)make. *Note:* In order to find the boost libraries provide $BOOST_INC_DIR and $BOOST_LIB_DIR environment variables, i.e.

export $BOOST_INC_DIR=path_to_boost/include/

export $BOOST_LIB_DIR=path_to_boost/lib/

## Features (Version 1.0)

Currently, ASCII file parsing from RESNUCLei scoring card (tab.lis) is implemented. Only conversion to Excel (xml format) is supported.

## Run

Run the program via the following command:
./FlukaConverter -i inputfile_tab.lis -o outputfile

## Contact

For bug reports and feature request just drop a line to marcus.matthias.morgenstern@cern.ch.
