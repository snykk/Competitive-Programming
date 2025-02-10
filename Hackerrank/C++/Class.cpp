#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    private:
        int age, standart;
        string first_name,last_name;
    public:
        void set_age(int Age) {
            age = Age;
        }
        void set_standard(int Standart) {
            standart = Standart;
        }
        void set_first_name(string First_name) {
            first_name = First_name;
        }
        void set_last_name(string Last_name) {
            last_name = Last_name;
        }
        
        int get_age() {
            return age;
        }
        int get_standard() {
            return standart;
        }
        string get_first_name() {
            return first_name;
        }
        string get_last_name() {
            return last_name;
        }
        
        string to_string() {
            string result = std::to_string(age) + "," + first_name  + "," + last_name  + "," + std::to_string(standart);
            return result;
        }
    
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
