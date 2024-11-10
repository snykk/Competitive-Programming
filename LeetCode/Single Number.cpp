class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR properties that make it useful here:
        // 1. a ^ a = 0 (any number XOR'd with itself is 0)
        // 2. a ^ 0 = a (any number XOR'd with 0 remains unchanged)
        // 3. XOR is commutative and associative, so order doesn't matter
        
        int result = 0;
        
        for (int num : nums) {
            result ^= num; 
        }
        
        return result;
    }
};
