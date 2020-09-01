//
// Created by flow on 2020-08-30.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <hyperGuess/Models/Number.hpp>

TEST_CASE("[Number] - Pick a number")
{
    hyperguess::Number number;

    number.Roll();

    // without parentheses, too many condition error occurred.
    CHECK((number.GetValue() >= 1 && number.GetValue() <= 100));
}