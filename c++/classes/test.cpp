#include "Car.hpp"

using namespace std;

void test() {
    cout << "In test" << endl;
    Car a = Car();
}

int main() {

    Car b("Honda", "Civic");
    Car c("Honda", "Civic", 2011);

    test();

    // Cannot set private members directly
    //b.year = 2011;
    b.setYear(-100);
    b.setYear(2011);

    cout << (b == c) << endl;
}
