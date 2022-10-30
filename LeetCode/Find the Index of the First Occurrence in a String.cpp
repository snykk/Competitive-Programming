class Solution {
public:
    bool isSubstrEqual(string str1, string str2) {
        int length = str1.length();
        for (int i = 0; i < length; i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }

        return true;
    }
    
    int strStr(string haystack, string needle) {
        int lengthDiff = haystack.length() - needle.length();
        for (int i = 0; i <= lengthDiff; i ++) {
            if (isSubstrEqual(haystack.substr(i, needle.length()), needle)) {
                return i;
            }
        }

        return -1;
    }
};