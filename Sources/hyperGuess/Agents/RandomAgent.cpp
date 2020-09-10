//
// Created by flow on 2020-09-01.
//

#include <hyperGuess/Agents/RandomAgent.hpp>

#include <effolkronium/random.hpp>

namespace hyperguess
{
int RandomAgent::GetAction([[maybe_unused]] const Game &state)
{
    using Random = effolkronium::random_static;

    return Random::get(1, 1000);
}
}  // namespace hyperguess