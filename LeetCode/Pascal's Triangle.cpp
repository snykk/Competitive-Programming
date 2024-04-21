class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0)
            return triangle;

        triangle.push_back({1});  // First row

        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize row with all 1s

            // Fill in the values for the current row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};