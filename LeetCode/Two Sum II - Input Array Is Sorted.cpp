class Solution {
public:
    // Using HashMap, poor memory though
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     unordered_map<int, int> mp;

    //     for (int i = 0; i < numbers.size(); i++) {
    //         if (mp.count(target - numbers[i])) return {mp[target-numbers[i]], i+1};

    //         mp[numbers[i]] = i+1;
    //     }

    //     return {};
    // }

    // Using pointer concept, less memory usage
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1}; 
            else if (sum < target) left++; 
            else right--; 
        }
        return {}; 
    }
};