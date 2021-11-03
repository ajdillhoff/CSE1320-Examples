#include "Weapon.hpp"

Weapon::Weapon() {
    name_ = "Fists";
    hit_bonus_ = 0;
    damage_ = Damage(Dice::d4, 1, 0);
}

Weapon::Weapon(string name, int hitBonus, Damage damage) {
    name_ = name;
    hit_bonus_ = hitBonus;
    damage_ = damage;
}

Weapon::Weapon(string name, int hitBonus, Dice dice, int numDice, int dmgBonus) {
    name_ = name;
    hit_bonus_ = hitBonus;
    damage_ = Damage(dice, numDice, dmgBonus);
}
