#pragma once

#include "utils.hpp"
#include "Weapon.hpp"
#include "Damage.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
    protected:
        string name_;
        int level_;
        int hp_;
        int ac_;
        int speed_;
        int str_;
        int dex_;
        int con_;
        int int_;
        int wis_;
        int cha_;
        Weapon weapon_;

    public:
        Character(string);
        Character(string, int, int, int, int);
        Character() : name_{"Undefined"} {}
        ~Character() {}

        /*
         * Getters/Setters
         */

        auto & name() { return name_; }
        const auto & name() const { return name_; }

        auto & level() { return level_; }
        const auto & level() const { return level_; }

        auto & hp() { return hp_; }
        const auto & hp() const { return hp_; }

        auto & ac() { return ac_; }
        const auto & ac() const { return ac_; }

        auto & speed() { return speed_; }
        const auto & speed() const { return speed_; }

        auto & strength() { return str_; }
        const auto & strength() const { return str_; }

        auto & dexterity() { return dex_; }
        const auto & dexterity() const { return dex_; }

        auto & constitution() { return con_; }
        const auto & constitution() const { return con_; }

        auto & wisdom() { return wis_; }
        const auto & wisdom() const { return wis_; }

        auto & intelligence() { return int_; }
        const auto & intelligence() const { return int_; }

        auto & charisma() { return cha_; }
        const auto & charisma() const { return cha_; }

        auto & weapon() { return weapon_; }
        const auto & weapon() const { return weapon_; }

        /*
         * Overloaded Functions
         */

        friend ostream& operator<<(ostream& os, Character const & c) {
            return os << c.name() << ", level " << c.level() << endl;
        }

        /*
         * Functions
         */

        bool takeDamage(int damage) {
            cout << name_ << " takes " << damage << " damage." << endl;

            if (hp_ - damage <= 0) {
                hp_ = 0;
                cout << name_ << " is unconscious!" << endl;
                return true;
            } else {
                hp_ -= damage;
                cout << name_ << " has " << hp_ << " HP remaining." << endl;
                return false;
            }
        }

        void attack(Character& c);
};
