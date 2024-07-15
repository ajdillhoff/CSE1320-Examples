#include "Character.hpp"

Character::Character(string name) {
    name_ = name;
    level_ = 1;
    hp_ = 10;
    ac_ = 14;
    speed_ = 30;
    str_ = 10;
    dex_ = 10;
    dex_ = 10;
    con_ = 10;
    wis_ = 10;
    int_ = 10;
}

void Character::attack(Character& c) {
    // Roll for an attack
    int hit = rollDice(Dice::d20);
    hit += weapon_.hitBonus();

    cout << name_ << " rolled a " << hit << " to attack!" << endl;

    // Check AC of target
    if (hit < c.ac()) {
        cout << "Miss!" << endl;
        return;
    }

    // Roll damage
    int damage = weapon_.damage().roll();

    cout << name_ << " strikes for " << damage << " damage." << endl;

    // Send raw damage
    c.takeDamage(damage);
}
