#pragma once

#include <string>

using namespace std;

class Item {
    private:
        string name_;
        int value_;
    public:
        Item() : name_{"Undefined"} {}
        Item(string name) : name_{name} {}
        Item(string name, int value) : name_{name}, value_{value} {}
        ~Item() {}
};
