class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int length = s.size(), step;

        if (numRows == 1) return s;

        for (int i = 0; i < numRows; i++) {
            step = 1;

            for (int j = i; j < length; j = j + 2 * numRows - 2){
                result += s[j];

                if (i % numRows && i % numRows != numRows - 1 && step * (2 * numRows - 2) - i % numRows < length) {
                    result += s[step * (2 * numRows - 2) - i % numRows];
                }

                step++;
            }
        }

        return result;
    }
};