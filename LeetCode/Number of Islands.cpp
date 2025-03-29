// Using Breadth First Search
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty()) return 0;
//         int result = 0;

//         int rows = grid.size();
//         int cols = grid[0].size();
//         set<pair<int,int>> visit;

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == '1' and !visit.contains({r, c})) {
//                     bfs(grid, rows, cols, r, c, visit);
//                     result++;
//                 }
//             }
//         }

//         return result;
//     }

// private:
//     void bfs(
//         const vector<vector<char>>& grid, 
//         const int& rows, const int& cols, 
//         int r, int c, 
//         set<pair<int,int>>& visit) {
//             vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//             queue<pair<int,int>> q;
//             visit.insert({r, c});
//             q.push({r,c});

//             while (!q.empty()) {
//                 auto [row, col] = q.front();
//                 q.pop();

//                 for (auto [dr, dc] : directions) {
//                     r = row+dr;
//                     c = col+dc;

//                     if ((0 <= r && r < rows) && (0 <= c && c < cols) && grid[r][c] == '1' && !visit.contains({r, c})) {
//                         q.push({r, c});
//                         visit.insert({r, c});
//                     }
//                 }
//             }
//         }
// };

// using Depth First Search
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int result = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Iterate through the entire grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If land ('1') is found, start a DFS search
                if (grid[r][c] == '1') {
                    dfs(grid, r, c); // Mark all connected land
                    result++;
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Ensure we are within bounds and only process land ('1')
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }

        // Mark the current cell as visited by changing '1' to '0'
        grid[r][c] = '0';

        // Explore all 4 directions (down, up, right, left)
        dfs(grid, r + 1, c);  // Down
        dfs(grid, r - 1, c);  // Up
        dfs(grid, r, c + 1);  // Right
        dfs(grid, r, c - 1);  // Left
    }
};
