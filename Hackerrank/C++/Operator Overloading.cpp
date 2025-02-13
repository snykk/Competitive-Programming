#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    vector<vector<int>> a;

    // Overload + operator to add two matrices
    Matrix operator+(const Matrix& other) {
        int rows = a.size(), cols = a[0].size();
        Matrix result;
        result.a.resize(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.a[i][j] = a[i][j] + other.a[i][j];

        return result;
    }
};

int main() {
    int T;  
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        Matrix m1, m2;
        m1.a.resize(N, vector<int>(M));
        m2.a.resize(N, vector<int>(M));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> m1.a[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> m2.a[i][j];

        Matrix result = m1 + m2;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << result.a[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
