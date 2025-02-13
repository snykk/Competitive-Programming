#include <iostream>
#include <iomanip> // for formatting output

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        double A, B, C;
        cin >> A >> B >> C;

        // Print A as a hexadecimal (lowercase) without decimal part
        cout << "0x" << hex << nouppercase << (long long)A << endl;

        // Print B with 2 decimal places, width = 15, right-justified with '_', and always show sign
        cout << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;

        // Print C in scientific notation with 9 decimal places, uppercase
        cout << scientific << uppercase << setprecision(9) << noshowpos << C << endl;
    }

    return 0;
}
