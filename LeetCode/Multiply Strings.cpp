class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int n = num1.length(), m = num2.length();
        vector<int> resV(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + resV[p2];
                resV[p1] += sum / 10;
                resV[p2] = sum % 10;
            }
        }

        for (int num : resV) {
            if (num == 0 && res.empty()) {
                continue;
            }
            res += to_string(num);
        }
        
        return res.empty() ? "0" : res;
    }

};