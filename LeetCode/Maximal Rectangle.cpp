class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int res = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            stack<int> st;
            
            for (int j = 0; j <= cols; j++) {
                while (!st.empty() && (j == cols || heights[st.top()] >= heights[j])) {
                    int topIndex = st.top();
                    st.pop();
                    int width = st.empty() ? j : (j - st.top() - 1);
                    int area = heights[topIndex] * width;
                    res = max(res, area);
                }
                
                st.push(j);
            }
        }
        
        return res;
    }
};