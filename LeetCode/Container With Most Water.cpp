class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = INT_MIN, left_line = 0, right_line = height.size() - 1;
        int length, area;

        while(left_line < right_line){
            length = min(height[left_line], height[right_line]);
            area = length * (right_line - left_line);
            result = max(result, area);
            if(length == height[left_line]){
                left_line++;
                continue;
            }

            right_line--;
        }

        return result;
    }
};