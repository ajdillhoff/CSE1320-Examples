#pragma once

#include <iostream>
#include <string>
#include "Automobile.hpp"

using namespace std;

class Car : public Automobile {
    private:
        string make;
        string model;
        int year;
        bool is_locked;
        double speed_;
        double acceleration_factor_;

    public:
        /*
         * Constructors
         */
        Car(string ma, string mo, int y) : make{ma}, model{mo}, year{y} {
            acceleration_factor_ = 1.2;
            speed_ = 0;
            is_locked = true;
            cout << "Constructor 1 called." << endl;
        }

        Car(string ma, string mo) : make{ma}, model{mo}, year{0} {
            acceleration_factor_ = 1.2;
            speed_ = 0;
            is_locked = true;
            cout << "Constructor 2 called." << endl;
        }

        Car() : make{"Test"}, model{"Test"}, year{0} {
            acceleration_factor_ = 1.2;
            speed_ = 0;
            is_locked = true;
            cout << "Default constructor called." << endl;
        }

        ~Car() {}

        /*
         * Setters/Getters
         */
        double speed() const {
            return speed_;
        }

        /*
         * Operators
         */
        bool operator==(const Car& b) {
            return (make == b.make) && (model == b.model) && (year == b.year);
        }

        /*
         * Functions
         */
        void Accelerate();
        bool LockCar();
};
