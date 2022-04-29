#include "Motorcycle.hpp"

void Motorcycle::Accelerate() {
    if (speed_ == 0) {
        speed_ = 1;
    }
    speed_ += speed_ * acceleration_factor_;
}
