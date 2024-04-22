class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        vector<int> cuts(n, 0);
        
        for (int end = 0; end < n; ++end) {
            int min_cut = end;
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || is_palindrome[start + 1][end - 1])) {
                    is_palindrome[start][end] = true;
                    min_cut = (start == 0) ? 0 : min(min_cut, cuts[start - 1] + 1);
                }
            }
            cuts[end] = min_cut;
        }
        
        return cuts[n - 1];
    }
};