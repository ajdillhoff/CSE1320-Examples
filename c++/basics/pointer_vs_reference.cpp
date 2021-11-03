#include <iostream>
#include <memory>
#include <string>

using namespace std;

void pass_value(int v) {
    v++; // Only changes the local copy
}

void pass_pointer(int *v_ptr) {
    (*v_ptr)++; // Changes the value pointed to by `v_ptr`.
}

/*
 * The syntax for using this function is cleaner than with
 * using a pointer.
 */
void pass_reference (int& v_ref) {
    v_ref++; // Changes the value that `v_ref` refers to.
}

int main() {
    int v = 10;
    int& v_ref {v}; // Reference to int
    v_ref++; // v is now 11
    cout << "v_ref = " << v_ref << endl;

    pass_value(v);
    cout << "v after pass_value(v) = " << v << endl;
    pass_value(v_ref);
    cout << "v after pass_value(v_ref) = " << v << endl;
    //pass_pointer(v_ref); // invalid!

    pass_pointer(&v);
    cout << "v after pass_pointer(&v) = " << v << endl;
    pass_reference(v_ref);
    cout << "v after pass_reference(v_ref) = " << v << endl;

    return 0;
}
