/*
 * This example creates two separate threads that present multiple lines of output each.
 * This time, a lock is used to make sure one thread is finished before the other begins.
 *
 * To compile: g++ thread_lock.cpp -lpthread
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;

void f1() {
    unique_lock<mutex> lck {m};
    cout << "f1() acquired lock..." << endl;
    for (int i = 0; i < 100; i++) {
        cout << "f1(): i = " << i << endl;
    }
}

void f2() {
    unique_lock<mutex> lck {m};
    cout << "f2() acquired lock..." << endl;
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
