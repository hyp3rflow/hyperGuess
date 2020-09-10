//
// Created by flow on 2020-09-01.
//

#ifndef HYPERGUESS_IAGENT_HPP
#define HYPERGUESS_IAGENT_HPP

#include <hyperGuess/Enums/GameEnums.hpp>
#include <hyperGuess/Games/Game.hpp>

namespace hyperguess
{
//!
//! \brief IAgent class.
//!
//! This class is an interface of agent classes.
//!
class IAgent
{
 public:
    //! Default virtual destructor.
    virtual ~IAgent() = default;

    //! Gets an action of agent.
    //! \param state The current game state.
    //! \return An action of agent.
    virtual int GetAction(const Game &state) = 0;
};
}  // namespace hyperguess

#endif  // HYPERGUESS_IAGENT_HPP
