//
// Created by flow on 2020-09-01.
//

#ifndef HYPERGUESS_GAME_HPP
#define HYPERGUESS_GAME_HPP

#include <array>
#include <hyperGuess/Enums/GameEnums.hpp>

namespace hyperguess
{
class Game
{
 public:
    //! Constructs game with given \p number.
    //! \param number The answer.
    explicit Game(int answer);

    void Reset(int answer);

    [[nodiscard]] int GetAnswer() const;

    ResultType GetNumberState(int number) const;

    void IncreaseCount();

    [[nodiscard]] int GetCount() const;

    //! Gets a game state.
    //! \return A game state.
    [[nodiscard]] PlayState GetPlayState() const;

    //! Processes the guessed number.
    //! \param number Check the number boolean value in array.
    void ProcessNumber(int number);

    //! Check \p number is equal or (greater or less than answer)
    //! \param number The guessing number.
    //! \return The ResultType of the result.
    [[nodiscard]] ResultType CheckPickedNumber(int number) const;

 private:
    PlayState gameState = PlayState::INVALID;

    int count = 0;
    int answer = 0;
    std::array<ResultType, 1001> picked_numbers{};
};
}  // namespace hyperguess

#endif  // HYPERGUESS_GAME_HPP
