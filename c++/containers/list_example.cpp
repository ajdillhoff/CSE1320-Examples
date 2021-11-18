#include <iostream>
#include <list>
#include <string>

using namespace std;

class Ship {
    string name_;
    int id_;

    public:
        Ship(string name, int id) : name_{name}, id_{id} {}

        auto & name() const { return name_; }
        auto & name() { return name_; }

        auto & id() const { return id_; }
        auto & id() { return id_; }

        friend ostream& operator<<(ostream& os, const Ship& ship) {
            return os << "{\"" << ship.name() << "\", " << ship.id() << "}";
        }
};

bool compare_id(const Ship& first, const Ship& second) {
    return first.id() < second.id();
}

int main() {
    list<Ship> ships {
        {"Rocinante", 2},
        {"Nebuchadnezzar", 1}
    };

    // Insert an existing ship to index 1
    list<Ship>::iterator iter = ships.begin();
    iter++; // Now points to index 1
    Ship new_ship = Ship{"Somnambulist", 4};
    ships.insert(iter, new_ship);

    // Add a new element to the back of the list
    ships.emplace_back("Millenium Falcon", 3);

    // Print out the ship names
    for (const auto & ship : ships) {
        cout << ship << endl;
    }

    // Sort the elements based on their id
    ships.sort(compare_id);

    cout << "After sort..." << endl;
    // Print out the ship names
    for (const auto & ship : ships) {
        cout << ship << endl;
    }

    return 0;
}
