#include "Car.hpp"

using namespace std;

int main() {

    Car a(); // default constructor
    Car b("Honda", "Civic");
    Car c("Honda", "Civic", 2011);

    // Cannot set private members directly
    //b.year = 2011;

    cout << (b == c) << endl;
}
