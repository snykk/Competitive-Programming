#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string first_name_;
    string last_name_;

public:
    Person(string first_name, string last_name) : first_name_(first_name), last_name_(last_name) {}

    // Overload << operator
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "first_name=" << p.first_name_ << ",last_name=" << p.last_name_;
        return os;
    }
};

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> ws;
    getline(cin, event);

    Person p(first_name, last_name);
    cout << p << " " << event << endl;

    return 0;
}