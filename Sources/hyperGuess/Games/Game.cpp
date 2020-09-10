//
// Created by flow on 2020-09-01.
//

#include <hyperGuess/Games/Game.hpp>

namespace hyperguess
{
Game::Game(int answer)
{
    Game::answer = answer;
    picked_numbers.fill(ResultType::EMPTY);
    gameState = PlayState::PLAYING;
}

void Game::Reset(int newAnswer)
{
    answer = newAnswer;
    count = 0;

    picked_numbers.fill(ResultType::EMPTY);

    gameState = PlayState::PLAYING;
}

int Game::GetAnswer() const
{
    return answer;
}

ResultType Game::GetNumberState(int number) const
{
    return picked_numbers.at(number);
}

void Game::IncreaseCount()
{
    count++;
}

int Game::GetCount() const
{
    return count;
}

PlayState Game::GetPlayState() const
{
    return gameState;
}

void Game::ProcessNumber(int number)
{
    if (picked_numbers[number] != ResultType::EMPTY)
    {
        return;
    }

    picked_numbers[number] = CheckPickedNumber(number);
    if (picked_numbers[number] == ResultType::EQUAL)
    {
        gameState = PlayState::WON;
    }

    IncreaseCount();
}

[[nodiscard]] ResultType Game::CheckPickedNumber(int number) const
{
    if (number == answer)
        return ResultType::EQUAL;
    else if (number < answer)
        return ResultType::UP;
    else
        return ResultType::DOWN;
}
}  // namespace hyperguess