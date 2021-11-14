#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream ofs {"sample.csv"};

    string firstname = "Naomi";
    string lastname = "Nagata";
    string email = "naomi@rocinante.com";

    ofs << firstname << "," << lastname << "," << email << endl;

    ofs.close();

    return 0;
}
