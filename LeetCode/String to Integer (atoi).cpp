class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        bool neg = false;
        int idx = str.find_first_not_of(' ');
        int max = 2147483647;
        int min = -2147483647;

        if (idx != string::npos) {
            str=str.substr(idx);
        }

        if (str[0] == '-') neg = true;

        if (str[0] == '-' || str[0] == '+' ) {str.erase(str.begin()); }

        if (str[0] < '0' || str[0] > '9') return 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') break;
            
            if (str[i] < '0' || str[i] > '9') break;
            
            if ((res*10 + str[i]-'0') > max) return neg ? min-1 : max;


            res = res*10 + str[i]-'0';

        }

        return neg ? res*-1 : res;
    }
};