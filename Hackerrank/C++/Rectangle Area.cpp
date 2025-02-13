#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width, height;

public:
    void display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
    }
    
    void display() {
        cout << (width * height) << endl;
    }
};

int main() {
    RectangleArea r;
    r.read_input();
    r.Rectangle::display();  // Print width and height
    r.display();             // Print area
    return 0;
}
