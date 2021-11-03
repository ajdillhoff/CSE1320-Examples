#pragma once

#include "Character.hpp"

class Player : public Character {
    public:
        Player(string name) : Character(name) {}
};
