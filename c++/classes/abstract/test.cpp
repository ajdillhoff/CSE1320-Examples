#include "Car.hpp"
#include "Motorcycle.hpp"
#include <vector>

using namespace std;

void test() {
    Motorcycle bike("Yamaha", "YZFR1", 2022);
}

int main() {

    Car car("Ferrari", "F50", 1995);
    Motorcycle bike("Yamaha", "YZFR1", 2022);

    car.Accelerate();
    bike.Accelerate();

    test();

    cout << "The car is travelling " << car.speed() << " km/h" << endl;
    cout << "The bike is travelling " << bike.speed() << " km/h" << endl;
}
