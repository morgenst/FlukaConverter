cmake_minimum_required(VERSION 3.3)
project(FlukaConverter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES main.cpp src/Converter.cpp include/Converter.h include/ParsedElement.h src/ParsedElement.cpp include/ReaderPolicy.h src/ReaderPolicy.cpp include/Converter.tcc include/Exceptions.h)

include_directories(include $ENV{BOOST_INC_DIR})
link_directories($ENV{BOOST_LIB_DIR})
add_executable(FlukaConverter ${SOURCE_FILES})
target_link_libraries(FlukaConverter stdc++ boost_program_options)