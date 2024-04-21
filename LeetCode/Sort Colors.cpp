class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Step 1: Count occurrences of each color
        int count[3] = {0}; // Count array to store occurrences of colors
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Overwrite the original array with counted colors in correct order
        int index = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                nums[index++] = i;
            }
        }
    }
};