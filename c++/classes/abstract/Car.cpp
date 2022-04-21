#include "Car.hpp"

void Car::Accelerate() {
    if (speed_ == 0) {
        speed_ = 1;
    }
    speed_ += speed_ * acceleration_factor_;
}

// Note the use of `this`
bool Car::LockCar() {
    if (this->is_locked) {
        return true;
    } else {
        this->is_locked = true;
        return false;
    }
}
