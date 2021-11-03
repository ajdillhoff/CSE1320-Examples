#include <iostream>
#include <memory>

using namespace std;

struct Car {
    int num_wheels;
    int horsepower;
};

int main() {
    Car *c = new Car;

    cout << "How many wheels does the car have? " << endl;
    cin >> c->num_wheels;

    if (c->num_wheels > 4) {
        delete c;
        cout << "deleting..." << endl;
    }

    // If the number of wheels is <= 4 then the object is never deleted.
}
