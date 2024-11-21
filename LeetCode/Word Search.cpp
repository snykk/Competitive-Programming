class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start a backtracking search if the first character matches
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        // Base case: if all characters are matched
        if (index == word.size()) {
            return true;
        }

        // Boundary and validity checks
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the cell as visited by modifying it temporarily
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) || // Down
                     dfs(board, word, i - 1, j, index + 1) || // Up
                     dfs(board, word, i, j + 1, index + 1) || // Right
                     dfs(board, word, i, j - 1, index + 1);   // Left

        // Restore the cell's original value
        board[i][j] = temp;

        return found;
    }
};
