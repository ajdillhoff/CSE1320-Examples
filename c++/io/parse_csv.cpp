#include <iostream>
#include <vector>

using namespace std;

vector<string> parse_csv_line(string csv_line) {
    size_t cur = 0;
    size_t last = 0;
    string token;
    vector<string> tokens;

    while ((cur = csv_line.find(",", last)) != string::npos) {
        token = csv_line.substr(last, cur - last);
        last = cur + 1;
        tokens.push_back(token);
    }

    // Read the last line
    tokens.push_back(csv_line.substr(last));

    return tokens;
}

int main() {
    string test = "First,Last,first@last.com,1234";

    vector<string> tokens = parse_csv_line(test);

    for (auto token : tokens) {
        cout << token << endl;
    }

    return 0;
}
