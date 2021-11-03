#pragma once

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

enum Dice {
    d4 = 4,
    d6 = 6,
    d8 = 8,
    d10 = 10,
    d12 = 12,
    d20 = 20
};

/*
 * Function Declarations
 */

int rollDice(Dice);
vector<string> tokenizeCSVLine(string);
