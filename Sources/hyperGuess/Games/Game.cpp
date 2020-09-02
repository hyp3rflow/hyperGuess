//
// Created by flow on 2020-09-01.
//

#include <hyperGuess/Games/Game.hpp>

namespace hyperguess {
    Game::Game(int answer) {
        Game::answer = answer;
        picked_numbers.fill({});
        gameState = PlayState::PLAYING;
    }

    int Game::GetAnswer() const {
        return answer;
    }

    int Game::GetCount() const {
        return count;
    }

    PlayState Game::GetPlayState() const {
        return gameState;
    }

    void Game::CheckGameState() {
        if (picked_number == answer) {
            gameState = PlayState::WON;
        }
    }

    ResultType Game::ProcessNumber(int number) {
        picked_number = number;
        count++;

        CheckGameState();

        if (!picked_numbers.at(number - 1)) {
            picked_numbers.at(number - 1) = true;
        }

        return CheckPickedNumber(number);
    }

    [[nodiscard]] ResultType Game::CheckPickedNumber(int number) const {
        if (number == answer) return ResultType::EQUAL;
        if (number > answer) return ResultType::UP;
        if (number < answer) return ResultType::DOWN;
    }
}// namespace hyperguess