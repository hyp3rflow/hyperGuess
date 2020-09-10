//
// Created by flow on 2020-09-01.
//

#ifndef HYPERGUESS_RANDOMAGENT_HPP
#define HYPERGUESS_RANDOMAGENT_HPP

#include <hyperGuess/Agents/IAgent.hpp>

namespace hyperguess
{
class RandomAgent final : public IAgent
{
 public:
    virtual ~RandomAgent() = default;

    int GetAction(const Game& state) override;
};
}  // namespace hyperguess

#endif  // HYPERGUESS_RANDOMAGENT_HPP
