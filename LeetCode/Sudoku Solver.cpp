class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        recSolver(board, 0, 0);
    }
    
private:
    bool recSolver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        
        if (col == 9) {
            return recSolver(board, row + 1, 0);
        }
        
        if (board[row][col] != '.') {
            return recSolver(board, row, col + 1);
        }
        
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (recSolver(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c || board[i][col] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
};
