#include "Monster.hpp"

Monster::Monster(string name) : Character(name) {
    weapon() = Weapon("Base", 0, Dice::d6, 1, 0);
}

Monster::Monster(string name, int cr, int xp) : Character(name), cr_{cr}, xp_{xp} {
    weapon() = Weapon("Base", 0, Dice::d6, 1, 0);
}

/*
 * Functions
 */

void Monster::loadFromCSV(string line) {
    vector<string> tokens = tokenizeCSVLine(line);

    name_ = tokens[0];
    level_ = stoi(tokens[1]);
    hp_ = stoi(tokens[2]);
    ac_ = stoi(tokens[3]);
    speed_ = stoi(tokens[4]);
    str_ = stoi(tokens[5]);
    dex_ = stoi(tokens[6]);
    con_ = stoi(tokens[7]);
    int_ = stoi(tokens[8]);
    wis_ = stoi(tokens[9]);
    cha_ = stoi(tokens[10]);
    weapon_ = Weapon("Bite", stoi(tokens[11]), Damage(tokens[12]));
}
