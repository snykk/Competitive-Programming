class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) // Skip non-alphanumeric characters from the left
                left++;
            while (left < right && !isalnum(s[right])) // Skip non-alphanumeric characters from the right
                right--;

            // Convert characters to lowercase before comparing
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};