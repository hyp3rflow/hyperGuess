//
// Created by flow on 2020-09-10.
//

#include <Games/Game.hpp>

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pyGuess, m)
{
    m.doc() = R"pbdoc(Guessing game simulator with some reinforcement learning)pbdoc";

    AddGame(m);
}