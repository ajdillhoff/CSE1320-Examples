#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // Loop through arguments and store them as strings.
    vector<string> args;

    // Only store tokens that appear after the program name
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // Print them out
    for (auto arg : args) {
        cout << arg << endl;
    }

    return 0;
}
