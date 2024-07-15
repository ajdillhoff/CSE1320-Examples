#include <iostream>
#include <memory>

using namespace std;

struct Car {
    int num_wheels;
    int horsepower;
};

bool has_equal_wheels(unique_ptr<Car>& b, unique_ptr<Car>& c) {
    if (b->num_wheels == c->num_wheels) {
        return true;
    } else {
        return false;
    }
}

int main() {
    unique_ptr<Car> b {new Car};
    unique_ptr<Car> c {new Car};

    b->num_wheels = 4;
    c->num_wheels = 4;

    cout << has_equal_wheels(b, c) << endl;
}
