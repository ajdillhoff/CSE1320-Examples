#include <iostream>
#include <memory>

using namespace std;

struct Car {
    int num_wheels;
    int horsepower;
};

// The shared_ptr is copied here, thus there will be 2 references
void print_wheels(shared_ptr<Car> c) {
    cout << "Wheels: " << c->num_wheels << endl;
}

int main() {

    // At this point, there is only one reference ot this pointer.
    shared_ptr<Car> c {new Car};

    c->num_wheels = 4;

    print_wheels(c);
}
