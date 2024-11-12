class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> queens(n, -1); // track the column positions of queens
        backtrack(0, queens, count, n);
        return count;
    }

private:
    void backtrack(int row, vector<int>& queens, int& count, int n) {
        if (row == n) {
            count++;  // found a valid solution
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(queens, row, col)) {
                queens[row] = col;  // place queen
                backtrack(row + 1, queens, count, n);  // recur to place the next queen
                queens[row] = -1;  // remove queen (backtrack)
            }
        }
    }

    bool isValid(const vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; ++i) {
            // check if the same column or diagonal is attacked
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
};
