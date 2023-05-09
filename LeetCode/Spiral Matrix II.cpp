class Solution {
public:
    // similar problem -> https://github.com/snykk/Competitive-Programming/blob/master/Codewars/Python/Kyu4_Snail.py
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1, row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1;
        while (row_start <= row_end && col_start <= col_end) {
            // fill top row
            for (int i = col_start; i <= col_end; i++) {
                matrix[row_start][i] = num++;
            }
            row_start++;
            
            // fill right column
            for (int i = row_start; i <= row_end; i++) {
                matrix[i][col_end] = num++;
            }
            col_end--;
            
            // fill bottom row
            if (row_start <= row_end) {
                for (int i = col_end; i >= col_start; i--) {
                    matrix[row_end][i] = num++;
                }
                row_end--;
            }
            
            // fill left column
            if (col_start <= col_end) {
                for (int i = row_end; i >= row_start; i--) {
                    matrix[i][col_start] = num++;
                }
                col_start++;
            }
        }
        return matrix;
    }
};