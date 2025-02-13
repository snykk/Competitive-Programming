#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> s;

    for (int i = 0; i < Q; i++) {
        int type, x;
        cin >> type >> x;

        switch (type) {
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(x);
                break;
            case 3:
                cout << (s.find(x) != s.end() ? "Yes" : "No") << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }
    }

    return 0;
}
