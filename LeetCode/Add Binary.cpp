class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        int sum;
        stringstream res;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res << (sum % 2);
            carry = sum / 2;
        }
        string result=res.str();
        reverse(result.begin(), result.end());
        return result;
    }
};