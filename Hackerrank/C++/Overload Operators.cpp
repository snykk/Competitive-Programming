#include <iostream>
using namespace std;

class Complex {
public:
    int a, b;

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex& other) {
        Complex result;
        result.a = a + other.a;
        result.b = b + other.b;
        return result;
    }

    // Overload << operator to print complex numbers in "a+ib" format
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.a << "+i" << c.b;
        return out;
    }
};

int main() {
    Complex c1, c2;
    char plus, i;

    // Read input in the format "a+ib"
    cin >> c1.a >> plus >> i >> c1.b;
    cin >> c2.a >> plus >> i >> c2.b;

    // Perform addition and print result
    Complex result = c1 + c2;
    cout << result << endl;

    return 0;
}
