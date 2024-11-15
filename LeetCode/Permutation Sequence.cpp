class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n, 1);
        string result;
        k--;  


        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        for (int i = n; i > 0; --i) {
            int idx = k / factorial[i - 1];
            result += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx); 
            k %= factorial[i - 1]; 
        }

        return result;
    }
};