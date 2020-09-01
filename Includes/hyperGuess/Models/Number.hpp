//
// Created by flow on 2020-08-30.
//

#ifndef HYPERGUESS_NUMBER_HPP
#define HYPERGUESS_NUMBER_HPP

namespace hyperguess {
    class Number {
    public:
        [[nodiscard]] int GetValue() const;
        void Roll();

    private:
        int value = 0;
    };
}// namespace hyperguess

#endif//HYPERGUESS_NUMBER_HPP
