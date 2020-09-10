//
// Created by flow on 2020-09-01.
//

#ifndef HYPERGUESS_GAMEENUMS_HPP
#define HYPERGUESS_GAMEENUMS_HPP

namespace hyperguess
{
//! \brief An enumerator for identifying the result type.
enum class ResultType
{
    UP,
    EQUAL,
    DOWN,
    EMPTY
};

//! \brief An enumerator for identifying the play state.
enum class PlayState
{
    INVALID,
    PLAYING,
    WON
};
}  // namespace hyperguess

#endif  // HYPERGUESS_GAMEENUMS_HPP
