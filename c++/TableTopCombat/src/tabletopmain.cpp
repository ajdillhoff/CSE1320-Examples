#include "Player.hpp"
#include "Monster.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<Monster> loadMonsters(string filename) {
    ifstream file(filename);
    vector<Monster> monsters;

    int i = 0;

    for (string line; getline(file, line); ) {
        // Skip the first line of the file.
        if (i == 0) {
            i++;
            continue;
        }
        // Monster initializes an object from CSV.
        Monster temp = Monster();
        temp.loadFromCSV(line);
        monsters.push_back(temp);
    }

    file.close();

    return monsters;
}

int main(int argc, char *argv[]) {
    Player p = Player("Vax'ildan");
    p.hp_ = 127;
    p.ac_ = 21;
    p.str_ = 14;
    p.dex_ = 20;
    p.con_ = 11;
    p.wis_ = 14;
    p.con_ = 11;
    p.cha_ = 14;
    p.weapon() = Weapon("Whisper", 3, Damage(Dice::d4, 1, 8));

    vector<Monster> monsters = loadMonsters("monsters.csv");

    Monster m = monsters[0];

    cout << p;
    cout << m;

    p.attack(m);
    m.attack(p);
}
