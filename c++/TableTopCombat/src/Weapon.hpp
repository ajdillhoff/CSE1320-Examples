#pragma once

#include "Damage.hpp"

class Weapon {
    string name_;
    int hit_bonus_;
    Damage damage_;
    int value_;

    public:
        Weapon();
        Weapon(string, int, Damage);
        Weapon(string, int, Dice, int, int);
        ~Weapon() {}

        /*
         * Getters/Setters
         */
        auto & name() { return name_; }
        const auto & name() const { return name_; }

        auto & hitBonus() { return hit_bonus_; }
        const auto & hitBonus() const { return hit_bonus_; }

        auto & damage() { return damage_; }
        const auto & damage() const { return damage_; }

        auto & value() { return value_; }
        const auto & value() const { return value_; }
};
