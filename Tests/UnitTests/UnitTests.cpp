//
// Created by flow on 2020-08-30.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <effolkronium/random.hpp>

#undef NEAR

#include <hyperGuess/Agents/IAgent.hpp>
#include <hyperGuess/Agents/RandomAgent.hpp>
#include <hyperGuess/Games/Game.hpp>

using namespace hyperguess;

TEST_CASE("Game - Basic") {
    using Random = effolkronium::random_static;
    int selected_answer = Random::get(1, 1000);

    Game game(selected_answer);

    CHECK(game.GetAnswer() == selected_answer);
    CHECK(game.GetPlayState() == PlayState::PLAYING);
    CHECK(game.GetCount() == 0);

    int test_count = 1;
    bool flag = true;
    while (test_count <= 100 && flag) {
        CHECK(game.GetPlayState() == PlayState::PLAYING);

        int guessed_number = Random::get(1, 1000);
        ResultType result = game.ProcessNumber(guessed_number);

        CHECK(game.GetCount() == test_count);

        if (result == ResultType::EQUAL) {
            flag = false;
            CHECK(guessed_number == selected_answer);
            CHECK(game.GetPlayState() == PlayState::WON);
        } else {
            if (guessed_number > selected_answer)
                CHECK(result == ResultType::UP);
            else
                CHECK(result == ResultType::DOWN);
            CHECK(guessed_number != selected_answer);
            CHECK(game.GetPlayState() == PlayState::PLAYING);
        }

        test_count++;
    }

    if (flag) {
        ResultType result = game.ProcessNumber(selected_answer);

        CHECK(result == ResultType::EQUAL);
        CHECK(game.GetPlayState() == PlayState::WON);
    }
}