class Solution {
public:
    // // Solution 1: DFS (Depth-First Search) implementation
    // void dfs(vector<vector<char>>& board, int r, int c) {
    //     int rows = board.size(), cols = board[0].size();
    //     if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') 
    //         return;
        
    //     board[r][c] = 'S'; // Mark as safe
    //     // Explore in 4 directions
    //     dfs(board, r + 1, c);
    //     dfs(board, r - 1, c);
    //     dfs(board, r, c + 1);
    //     dfs(board, r, c - 1);
    // }

    // void solve(vector<vector<char>>& board) {
    //     int rows = board.size(), cols = board[0].size();
    //     if (rows == 0 || cols == 0) return;

    //     // Mark all border-connected 'O' cells
    //     for (int i = 0; i < rows; ++i) {
    //         if (board[i][0] == 'O') dfs(board, i, 0);
    //         if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
    //     }
    //     for (int j = 0; j < cols; ++j) {
    //         if (board[0][j] == 'O') dfs(board, 0, j);
    //         if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
    //     }

    //     // Flip remaining 'O' to 'X', and 'S' back to 'O'
    //     for (int i = 0; i < rows; ++i) {
    //         for (int j = 0; j < cols; ++j) {
    //             if (board[i][j] == 'O') 
    //                 board[i][j] = 'X';  // Surrounded regions are flipped
    //             else if (board[i][j] == 'S') 
    //                 board[i][j] = 'O';  // Restore safe regions
    //         }
    //     }
    // }

    // Solution 2: BFS (Breadth-First Search) implementation
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        if (rows == 0 || cols == 0) return;

        queue<pair<int, int>> q;
        
        // Identify all border 'O' cells
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][cols - 1] == 'O') q.push({i, cols - 1});
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[rows - 1][j] == 'O') q.push({rows - 1, j});
        }

        // BFS to mark safe 'O's
        vector<int> directions = {-1, 0, 1, 0, -1}; // For 4-direction movement
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') 
                continue;
            
            board[r][c] = 'S'; // Mark as safe
            for (int k = 0; k < 4; ++k) {
                int nr = r + directions[k], nc = c + directions[k + 1];
                q.push({nr, nc});
            }
        }

        // Flip remaining 'O' to 'X', and 'S' back to 'O'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if (board[i][j] == 'S') 
                    board[i][j] = 'O';
            }
        }
    }
};
