//
// Created by flow on 2020-08-30.
//

#include <effolkronium/random.hpp>
#include <hyperGuess/Models/Number.hpp>

namespace hyperguess {
    int Number::GetValue() const {
        return value;
    }

    void Number::Roll() {
        using Random = effolkronium::random_static;

        value = Random::get<int>(1, 100);
    }
}// namespace hyperguess