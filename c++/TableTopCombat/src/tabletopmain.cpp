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
    p.hp() = 127;
    p.ac() = 21;
    p.strength() = 14;
    p.dexterity() = 20;
    p.constitution() = 11;
    p.wisdom() = 14;
    p.charisma() = 14;
    p.weapon() = Weapon("Whisper", 3, Damage(Dice::d4, 1, 8));

    vector<Monster> monsters = loadMonsters(argv[1]);

    Monster m = monsters[0];

    cout << p;
    cout << m;

    p.attack(m);
    m.attack(p);
}
