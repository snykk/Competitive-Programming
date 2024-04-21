class Solution {
public:
    bool isNumber(string s) {
        // Trim leading and trailing whitespaces
        int start = 0, end = s.length() - 1;
        while (start <= end && isspace(s[start])) {
            start++;
        }
        while (start <= end && isspace(s[end])) {
            end--;
        }
        // Check if the string is empty after trimming
        if (start > end) {
            return false;
        }

        bool digitSeen = false;
        bool dotSeen = false;
        bool expSeen = false;

        for (int i = start; i <= end; i++) {
            char c = s[i];

            if (isdigit(c)) {
                digitSeen = true;
            } else if (c == '.') {
                if (dotSeen || expSeen) {
                    return false;
                }
                dotSeen = true;
            } else if (c == 'e' || c == 'E') {
                if (expSeen || !digitSeen) {
                    return false;
                }
                expSeen = true;
                digitSeen = false; // Reset digit flag for the exponent
            } else if (c == '+' || c == '-') {
                if (i > start && (s[i - 1] != 'e' && s[i - 1] != 'E')) {
                    return false;
                }
            } else {
                return false; // Invalid character
            }
        }

        return digitSeen; // At least one digit must be seen
    }
};
