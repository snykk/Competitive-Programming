class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));  // initialze the board with '.'
        backtrack(0, board, results, n);
        return results;
    }

private:
    void backtrack(int row, vector<string>& board, vector<vector<string>>& results, int n) {
        if (row == n) {
            results.push_back(board);  // found a solution, add it to results
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';  // place queen
                backtrack(row + 1, board, results, n);  // recur to place the next queen
                board[row][col] = '.';  // remove queen (backtrack)
            }
        }
    }

    bool isValid(const vector<string>& board, int row, int col, int n) {
        // check if there is a queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        // check the diagonal from top-left to bottom-right
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // check the diagonal from top-right to bottom-left
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};
