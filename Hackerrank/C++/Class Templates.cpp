#include <iostream>
#include <string>
using namespace std;

// General template for int and float
template <class T>
class AddElements {
    T element;
public:
    AddElements(T arg) : element(arg) {} // Use initializer list
    T add(T arg) { return element + arg; }
};

// Template specialization for string
template <>
class AddElements<string> {
    string element;
public:
    AddElements(string arg) : element(std::move(arg)) {} // Move instead of copy
    string concatenate(string arg) { return element + arg; } // Efficient append
};

int main() {
    // Speed up input/output operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    while (n--) {
        string type;
        cin >> type;
        
        if (type == "int") {
            int a, b;
            cin >> a >> b;
            cout << AddElements<int>(a).add(b) << "\n";
        } 
        else if (type == "float") {
            float a, b;
            cin >> a >> b;
            cout << AddElements<float>(a).add(b) << "\n";
        } 
        else if (type == "string") {
            string a, b;
            cin >> a >> b;
            cout << AddElements<string>(std::move(a)).concatenate(std::move(b)) << "\n";
        }
    }
    
    return 0;
}
