#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0 || n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=" + to_string(n));
    }
    for (int i = n / 2; i > 0; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}

void process_input(int n) {
    try {
        int result = largest_proper_divisor(n);
        cout << "result=" << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << "returning control flow to caller" << endl;}

int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
