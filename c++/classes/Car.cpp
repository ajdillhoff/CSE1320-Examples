#include "Car.hpp"

// Note the use of `this`
bool Car::lock_car() {
    if (this->is_locked) {
        return true;
    } else {
        this->is_locked = true;
        return false;
    }
}
