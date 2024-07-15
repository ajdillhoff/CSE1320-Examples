#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, double> stocks {
        {"TMO", 638.74},
        {"DHR", 323.96},
        {"ABT", 125.88},
        {"MDT", 111.05},
        {"ISRG", 329.23},
        {"SYK", 243.38},
        {"BDX", 245.90}
    };

    // Print all keys
    for (const auto & stock : stocks) {
        cout << stock.first << endl;
    }

    // Using the [] will return 0 if no key is found.
    auto result = stocks["AAPL"];
    cout << result << endl;

    // Print all keys
    for (const auto & stock : stocks) {
        cout << stock.first << " " << stock.second << endl;
    }

    // Using .at will throw an exception, which should be caught
    try {
        result = stocks.at("GME");
    } catch (out_of_range& e) {
        cout << "Key does not exist!" << endl;
    }

    // Finally, retrieve a key that exists.
    try {
        result = stocks.at("MDT");
        cout << result << endl;
    } catch (out_of_range& e) {
        cout << "Key does not exist!" << endl;
    }

    return 0;
}
