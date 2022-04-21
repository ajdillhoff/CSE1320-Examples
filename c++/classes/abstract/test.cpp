#include "Car.hpp"

using namespace std;

int main() {

    Car car("Ferrari", "F50", 1995);

    car.Accelerate();

    cout << "We are travelling " << car.speed() << " km/h" << endl;
}
