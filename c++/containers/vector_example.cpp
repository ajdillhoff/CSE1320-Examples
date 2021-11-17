#include <iostream>
#include <vector>

using namespace std;

class Ship {
    string name_;
    int id_;

    public:
        Ship(string name, int id) : name_{name}, id_{id} {}

        auto & name() const { return name_; }
        auto & name() { return name_; }
};

int main() {
    vector<Ship> ships {
        {"Rocinante", 1},
        {"Nebuchadnezzar", 2}
    };

    // Add an existing ship via `push_back`
    Ship new_ship = Ship{"Somnambulist", 3};
    ships.push_back(new_ship);

    // Add a ship that doesn't exist using argument constructors via `emplace_back`
    ships.emplace_back("Millenium Falcon", 4);

    // Get the number of items in the vector
    cout << "There are " << ships.size() << " ships." << endl;

    // Loop through ships
    for (auto s : ships) {
        cout << s.name() << endl;
    }

    // Remove the ship at index 1
    ships.erase(ships.begin() + 1);

    // Remove the last ship
    ships.pop_back();

    // Regular indexing does not throw an exception
    ships[10]; // valid

    // Using .at(int) will ensure that exceptions can be handled
    try {
        Ship s = ships.at(10);
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    // Remove all ships
    ships.clear();

    return 0;
}
