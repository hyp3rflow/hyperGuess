//
// Created by flow on 2020-09-10.
//

#include <Games/Game.hpp>
#include <hyperGuess/Games/Game.hpp>

using namespace hyperguess;

void AddGame(pybind11::module &m)
{
    pybind11::class_<Game>(m, "Game").def(pybind11::init<int>());
}