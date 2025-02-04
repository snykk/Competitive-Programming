class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;  // `ones` stores bits appearing once, `twos` stores bits appearing twice

        for (int num : nums) {
            // Step 1: Update `ones`
            // If `num` is seen for the first time, store it in `ones` using XOR
            // If `num` is seen again, it will be removed from `ones`
            // The `~twos` ensures that a number appearing in `twos` is removed from `ones`
            ones = (ones ^ num) & ~twos;

            // Step 2: Update `twos`
            // If `num` is seen for the second time, store it in `twos` using XOR
            // If `num` appears again (third time), it will be removed from `twos`
            // The `~ones` ensures that a number appearing in `ones` is removed from `twos`
            twos = (twos ^ num) & ~ones;
        }

        // Only the unique number remains in `ones`, because numbers appearing three times get cleared
        return ones;
    }
};
