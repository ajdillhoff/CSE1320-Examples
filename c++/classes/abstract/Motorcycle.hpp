#pragma once

#include <iostream>
#include <string>
#include "Automobile.hpp"

using namespace std;

class Motorcycle : public Automobile {
    private:
        string make;
        string model;
        int year;
        double speed_;
        double acceleration_factor_;

    public:
        /*
         * Constructors
         */
        Motorcycle(string ma, string mo, int y) : make{ma}, model{mo}, year{y} {
            acceleration_factor_ = 2.2;
            speed_ = 0;
            cout << "Constructor 1 called." << endl;
        }

        Motorcycle(string ma, string mo) : make{ma}, model{mo}, year{0} {
            acceleration_factor_ = 2.2;
            speed_ = 0;
            cout << "Constructor 2 called." << endl;
        }

        Motorcycle() : make{"Test"}, model{"Test"}, year{0} {
            acceleration_factor_ = 2.2;
            speed_ = 0;
            cout << "Default constructor called." << endl;
        }

        ~Motorcycle() {
            cout << "Motorcycle Destructor called." << endl;
        }

        /*
         * Setters/Getters
         */
        double speed() const {
            return speed_;
        }

        void setSpeed(double val) {
            if (val >= 0)
                speed_ = val;
            else {
                speed_ = 0;
            }
        }

        /*
         * Operators
         */
        bool operator==(const Motorcycle& b) {
            return (make == b.make) && (model == b.model) && (year == b.year);
        }

        /*
         * Functions
         */
        void Accelerate();
};
