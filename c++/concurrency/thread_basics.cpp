/*
 * This example creates two separate threads that present multiple lines of output each.
 * Notice how the other is not necessarily synchronized.
 *
 * To compile, you may need to include the library `-lpthread`.
 */

#include <iostream>
#include <thread>

using namespace std;

void f1() {
    for (int i = 0; i < 100; i++) {
        cout << "f1(): i = " << i << endl;
    }
}

void f2() {
    for (int i = 0; i < 100; i++) {
        cout << "f2(): i = " << i << endl;
    }
}

int main() {
    thread t1 {f1};
    thread t2 {f2};

    t1.join();
    t2.join();

    cout << "Complete." << endl;

    return 0;
}
