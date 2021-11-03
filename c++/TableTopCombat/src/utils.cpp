#include "utils.hpp"

using namespace std;

int rollDice(Dice dice) {
    random_device rdevice;

    mt19937::result_type seed = rdevice() ^ (
            (mt19937::result_type)
            chrono::duration_cast<chrono::seconds>(
                chrono::system_clock::now().time_since_epoch()
                ).count() +
            (mt19937::result_type)
            chrono::duration_cast<chrono::microseconds>(
                chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    mt19937 gen(seed);
    uniform_int_distribution<unsigned> dist(1, dice);

    cout << "[DEBUG] utils.cpp::rollDice(): dice = " << dice << endl;

    return dist(gen);
}

vector<string> tokenizeCSVLine(string line) {
    vector<string> tokens;
    stringstream lineStream(line);
    string temp;

    while (getline(lineStream, temp, ',')) {
        tokens.push_back(temp);
    }

    return tokens;
}
