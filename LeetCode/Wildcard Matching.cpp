class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        int s_index = 0;
        int p_index = 0;
        int star_index = -1;
        int s_tmp = -1;

        while (s_index < s_len) {
            if (p_index < p_len && (p[p_index] == '?' || p[p_index] == s[s_index])) {
                p_index++;
                s_index++;
            } else if (p_index < p_len && p[p_index] == '*') {
                star_index = p_index++;
                s_tmp = s_index;
            } else if (star_index != -1) {
                p_index = star_index + 1;
                s_index = ++s_tmp;
            } else {
                return false;
            }
        }

        return all_of(p.begin() + p_index, p.end(), [](char c) { return c == '*'; });
    }
};
