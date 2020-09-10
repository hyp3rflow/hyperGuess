//
// Created by flow on 2020-08-30.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <effolkronium/random.hpp>
#include "doctest.h"

#undef NEAR

#include <hyperGuess/Agents/IAgent.hpp>
#include <hyperGuess/Agents/RandomAgent.hpp>
#include <hyperGuess/Games/Game.hpp>

using namespace hyperguess;

TEST_CASE("Game - Basic")
{
    int answer = 47;

    Game game(answer);
    CHECK(game.GetAnswer() == 47);

    CHECK(game.GetCount() == 0);

    game.ProcessNumber(46);
    CHECK(game.GetNumberState(46) == ResultType::UP);

    CHECK(game.GetCount() == 1);

    game.ProcessNumber(47);
    CHECK(game.GetNumberState(47) == ResultType::EQUAL);
    CHECK(game.GetPlayState() == PlayState::WON);

    CHECK(game.GetCount() == 2);

    game.Reset(3);

    CHECK(game.GetCount() == 0);

    CHECK(game.GetNumberState(47) == ResultType::EMPTY);
    CHECK(game.GetPlayState() == PlayState::PLAYING);

    game.ProcessNumber(3);
    CHECK(game.GetNumberState(3) == ResultType::EQUAL);
    CHECK(game.GetPlayState() == PlayState::WON);

    CHECK(game.GetCount() == 1);
}

TEST_CASE("GAME - RandomAgent")
{
    Game game(43);

    RandomAgent agent;

    const int action = agent.GetAction(game);

    CHECK(((action >= 1) && (action <= 1000)));
}