#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int** arr = new int*[n];

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr[i] = new int[k];
        for (int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
