#include "Damage.hpp"

Damage::Damage(string dmg) {
    string delim1 = "d";
    string delim2 = "+";

    // Get number of dice
    string token = dmg.substr(0, dmg.find(delim1));
    numDice_ = stoi(token);

    dmg.erase(0, dmg.find(delim1) + delim1.length());

    // Get dice type
    token = dmg.substr(0, dmg.find(delim2));
    dice_ = Dice(stoi(token));

    dmg.erase(0, dmg.find(delim2) + delim2.length());

    // Get bonus
    bonus_ = stoi(dmg);
}

int Damage::roll() {
    int total = 0;
    cout << "[DEBUG] Damage.cpp::rolle(): numDice_ = " << numDice_ << endl;
    for (int i = 0; i < numDice_; i++) {
        total += rollDice(dice_);
        cout << "[DEBUG] Damage.cpp::roll(): total = " << total << endl;
    }

    total += bonus_;
    cout << "[DEBUG] Damage.cpp::roll(): total = " << total << endl;

    return total;
}
