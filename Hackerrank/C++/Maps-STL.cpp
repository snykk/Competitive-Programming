#include <iostream>
#include <map>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<string, int> studentMarks;

    for (int i = 0; i < Q; i++) {
        int type;
        string name;
        cin >> type >> name;

        switch (type) {
            case 1: {
                int marks;
                cin >> marks;
                studentMarks[name] += marks;
                break;
            }
            case 2:
                studentMarks.erase(name);
                break;
            case 3:
                cout << studentMarks[name] << endl;
                break;
            default:
                cout << "Invalid Query!" << endl;
                break;
        }
    }

    return 0;
}
