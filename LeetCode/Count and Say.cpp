class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n - 1);
        string result = "";
        char curr = prev[0];
        int count = 1;
        for (int i = 1; i < prev.length(); i++) {
            if (prev[i] == curr) {
                count++;
                continue;
            }

            result += to_string(count) + curr;
            curr = prev[i];
            count = 1;
        }

        result += to_string(count) + curr;
        return result;
    }


};