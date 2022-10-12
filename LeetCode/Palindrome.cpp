class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        string str = to_string(x);
        int length = str.length();
        int middle = length/2;
        
        for (int i = 0; i < middle; i++) {
            if (str[i] != str[length-1-i]) {
                return false;
            }
        }
        
        return true;
    }
};