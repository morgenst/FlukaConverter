cmake_minimum_required(VERSION 3.2)
project(FlukaConverter)

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # require at least gcc 4.8
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
        message(FATAL_ERROR "GCC version must be at least 4.8!")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # require at least clang 3.3
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3)
        message(FATAL_ERROR "Clang version must be at least 3.9!")
    endif()
else()
    message(WARNING "You are using an unsupported compiler! Compilation has only been tested with Clang and GCC.")
endif()

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES main.cpp include/Converter.h include/ParsedElement.h include/ReaderPolicy.h src/ReaderPolicy.cpp include/Converter.tcc include/Exceptions.h include/PredefinedConverters.h include/WriterPolicy.h include/Utils.h src/WriterPolicy.cpp include/Filter.h include/Filter.tcc src/Filter.cpp)

#currently boost 1.59 not working on mac
#include(BoostTestHelpers.cmake)
#add_boost_test(test/testExcelReader.cpp)
#add_boost_test(test/testUtils.cpp)

include_directories(include $ENV{BOOST_INC_DIR})
link_directories($ENV{BOOST_LIB_DIR})
add_executable(FlukaConverter ${SOURCE_FILES})
target_link_libraries(FlukaConverter stdc++ boost_system boost_filesystem boost_program_options)