//
// Created by flow on 2020-09-01.
//

#ifndef HYPERGUESS_GAME_HPP
#define HYPERGUESS_GAME_HPP

#include <hyperGuess/Enums/GameEnums.hpp>
#include <array>

namespace hyperguess {
    class Game {
    public:
        //! Constructs game with given \p number.
        //! \param number The answer.
        explicit Game(int answer);

        //! Reset data.
        void Reset();

        [[nodiscard]] int GetAnswer() const;
        [[nodiscard]] int GetCount() const;

        //! Gets a game state.
        //! \return A game state.
        [[nodiscard]] PlayState GetPlayState() const;

        //! Checks a game state.
        //! If player win, alter gameState value.
        void CheckGameState();

        //! Processes the guessed number.
        //! \param number Check the number boolean value in array.
        ResultType ProcessNumber(int number);

    private:
        PlayState gameState = PlayState::INVALID;

        int count = 0;
        int answer = 0;
        int picked_number = 0;
        std::array<bool, 1000> picked_numbers{};

        //! Check \p number is equal or (greater or less than answer)
        //! \param number The guessing number.
        //! \return The ResultType of the result.
        [[nodiscard]] ResultType CheckPickedNumber(int number) const;
    };
}// namespace hyperguess

#endif//HYPERGUESS_GAME_HPP
