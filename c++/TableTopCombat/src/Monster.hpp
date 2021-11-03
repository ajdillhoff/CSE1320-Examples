#pragma once

#include <string>
#include <vector>

#include "Character.hpp"

using namespace std;

class Monster : public Character {
    int cr_;
    int xp_;

    public:
        Monster() {}
        Monster(string);
        Monster(string, int, int);

        /*
         * Functions
         */
        void loadFromCSV(string);
};
