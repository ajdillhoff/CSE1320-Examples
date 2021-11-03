#include <iostream>
#include <memory>

using namespace std;

struct Car {
    int num_wheels;
    int horsepower;
};

int main() {
    unique_ptr<Car> c {new Car};

    cout << "How many wheels does the car have? " << endl;
    cin >> c->num_wheels;

    if (c->num_wheels > 4) {
        cout << "That's a lot of wheels." << endl;
    }

    // The object will be deleted automatically!
    // Verify with valgrind.
}
