class Solution {
public:
    // using variable to allow boundaries
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right on the top row
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            ++top;  // Move the top boundary down

            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            --right;  // Move the right boundary left

            // Traverse from right to left on the bottom row (if still within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;  // Move the bottom boundary up
            }

            // Traverse from bottom to top on the left column (if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                ++left;  // Move the left boundary right
            }
        }

        return result;
    }
    
    // // manipulate matrix
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     vector<int> result;

    //     while (!matrix.empty()) {
    //         // Add first row/list of matrix
    //         result.insert(result.end(), matrix.front().begin(), matrix.front().end());
    //         matrix.erase(matrix.begin());

    //         // Append Last element of all list in order
    //         if (!matrix.empty() && !matrix[0].empty()) {
    //             for (vector<int>& row : matrix) {
    //                 result.push_back(row.back());
    //                 row.pop_back();
    //             }
    //         }

    //             // Add reverse of last row/list
    //         if (!matrix.empty()) {
    //             result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
    //             matrix.pop_back();
    //         }

    //         // Append first element of all rows/list in reverse
    //         if (!matrix.empty() && !matrix[0].empty()) {
    //             for (int i = matrix.size() - 1; i >= 0; --i) {
    //                 result.push_back(matrix[i].front());
    //                 matrix[i].erase(matrix[i].begin());
    //             }
    //         }
    //     }

    //     return result;
    // }
};