class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        // Generate Gray code sequence for n-1 bits
        vector<int> prevSeq = grayCode(n - 1);
        // Add leading 0 to each element in the sequence
        for (int num : prevSeq) {
            result.push_back(num);
        }
        // Add leading 1 to each element in the reverse order of the sequence
        for (int i = prevSeq.size() - 1; i >= 0; --i) {
            result.push_back(prevSeq[i] + pow(2, n - 1));
        }
        return result;
    }
};