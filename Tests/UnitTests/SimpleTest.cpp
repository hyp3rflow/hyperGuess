//
// Created by flow on 2020-08-30.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cpp_practice/Test.hpp>

TEST_CASE("Simple Test")
{
    CHECK(Add(2, 3) == 5);
}