class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int i = 0;
        
        while (i < heights.size()) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
                continue;
            } 

            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            max_area = max(max_area, area);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};