#include <iostream>
#include <string>
using namespace std;

// Define Color enumeration with unique names
enum Color { red, green, orange_color };

// Define Fruit enumeration
enum Fruit { apple, orange, pear };

// Template class for mapping enumeration values to their names
template <typename T>
class Traits {
public:
    static string name(int index) {
        return "unknown";  // Default case for unknown types
    }
};

// Specialization for Color
template <>
class Traits<Color> {
public:
    static string name(int index) {
        static const string colors[] = { "red", "green", "orange" };
        if (index >= 0 && index < 3) return colors[index];
        return "unknown";
    }
};

// Specialization for Fruit
template <>
class Traits<Fruit> {
public:
    static string name(int index) {
        static const string fruits[] = { "apple", "orange", "pear" };
        if (index >= 0 && index < 3) return fruits[index];
        return "unknown";
    }
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int colorIndex, fruitIndex;
        cin >> colorIndex >> fruitIndex;

        cout << Traits<Color>::name(colorIndex) << " "
             << Traits<Fruit>::name(fruitIndex) << endl;
    }

    return 0;
}
