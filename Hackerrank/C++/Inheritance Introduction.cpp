#include <iostream>
using namespace std;

// Base class: Triangle
class Triangle {
public:
    void triangle() {
        cout << "I am a triangle" << endl;
    }
};

// Derived class: Isosceles
class Isosceles : public Triangle {
public:
    void isosceles() {
        cout << "I am an isosceles triangle" << endl;
    }

    // New function to print additional information
    void description() {
        cout << "In an isosceles triangle two sides are equal" << endl;
    }
};

int main() {
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
    return 0;
}
