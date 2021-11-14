#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream of {"sample.db", ios::binary};

    int a = 100;
    string s = "Test Output";

    of.write(s.c_str(), sizeof(s));
    of.write(reinterpret_cast<const char*>(&a), sizeof(int));

    of.close();

    return 0;
}
