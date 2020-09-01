//
// Created by flow on 2020-08-30.
//

#ifndef HYPERGUESS_NUMBER_HPP
#define HYPERGUESS_NUMBER_HPP

namespace hyperGuess {
    class Number {
    public:
        [[nodiscard]] int GetValue() const;
        void Roll();

    private:
        int value = 0;
    };
}// namespace hyperGuess

#endif//HYPERGUESS_NUMBER_HPP
