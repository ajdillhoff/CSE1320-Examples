#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<double> v;

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
        cout << v[i] << endl;
    }
}
