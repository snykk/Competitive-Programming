#include <iostream>
using namespace std;

// Recursively compute the decimal value from reversed binary digits
template <bool first>
constexpr int compute_binary_value() {
    return first ? 1 : 0;
}

template <bool first, bool second, bool... rest>
constexpr int compute_binary_value() {
    return (compute_binary_value<second, rest...>() << 1) + (first ? 1 : 0);
}

// Template struct to generate all possible 6-bit binary sequences
template <int n, bool... bits>
struct GenerateValues {
    static void evaluate(int target, int offset) {
        // Recursively generate sequences with leading 0 and 1
        GenerateValues<n - 1, 0, bits...>::evaluate(target, offset);
        GenerateValues<n - 1, 1, bits...>::evaluate(target, offset);
    }
};

// Base case: When the sequence length reaches 6, compute and compare values
template <bool... bits>
struct GenerateValues<0, bits...> {
    static void evaluate(int target, int offset) {
        int value = compute_binary_value<bits...>();
        cout << ((value + 64 * offset == target) ? '1' : '0');
    }
};

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int x, y;
        cin >> x >> y;

        // Generate and evaluate all possible binary sequences of length 6
        GenerateValues<6>::evaluate(x, y);
        cout << "\n";
    }

    return 0;
}
