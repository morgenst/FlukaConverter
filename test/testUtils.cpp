//
// Created by Marcus Morgenstern on 15/10/15.
//

#define BOOST_TEST_MODULE test
#include "boost/test/included/unit_test.hpp"

#include <vector>

#include "Utils.h"

using namespace boost::unit_test;
using namespace Utils;

BOOST_AUTO_TEST_CASE( test_getMaxSize ){
    auto testVec = std::vector<std::vector<float>>{};
    auto iTmp = 0;
    auto targetSize = 10;
    while(iTmp <= targetSize) {
        testVec.emplace_back(std::vector<float>(iTmp, 0.));
        ++iTmp;
    }
    BOOST_TEST(getMaxSize(&testVec) == targetSize);
}

BOOST_AUTO_TEST_CASE( test_getMaxSize_empty){
    auto testVec = std::vector<std::vector<float>>{};
    BOOST_TEST(getMaxSize(&testVec) == 0);
}