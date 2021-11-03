#pragma once

#include "utils.hpp"

using namespace std;

class Damage {
    Dice dice_;
    int numDice_;
    int bonus_;

    public:
        Damage(Dice dice, int numDice, int bonus) : dice_{dice}, numDice_{numDice}, bonus_{bonus} {}
        Damage(Dice dice, int numDice) : dice_{dice}, numDice_{numDice} {}
        Damage(Dice dice) : dice_{dice}, numDice_{1}, bonus_{0} {}
        Damage(string);
        Damage() {}
        ~Damage() {}

        /*
         * Functions
         */
        int roll();
};
