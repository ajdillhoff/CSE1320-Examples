#pragma once

#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        string make;
        string model;
        int year;
        bool is_locked;

    public:
        /*
         * Constructors
         */
        Car(string ma, string mo, int y) : make{ma}, model{mo}, year{y} {
            is_locked = true;
            cout << "Constructor 1 called." << endl;
        }

        Car(string ma, string mo) : make{ma}, model{mo}, year{0} {
            is_locked = true;
            cout << "Constructor 2 called." << endl;
        }

        Car() : make{"Test"}, model{"Test"}, year{0} {
            is_locked = true;
            cout << "Default constructor called." << endl;
        }

        ~Car() {
            cout << "Destructor called." << endl;
        }

        /*
        * Setters and Getters
        */
        int getYear() const {
            return year;
        }

        void setYear(int val) {
            if (val < 0) {
                cout << "Invalid year." << endl;
                return;
            }

            year = val;
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
        bool lock_car();
};
