class Solution {
public:
    int reverse(int x) {
        int MAX = 2147483647;
        int MIN = -2147483647;

        int isNegative = 1;
        if (x < 0 && x > MIN){
            isNegative = -1;
            x *= -1;
        } 
        int revInt = 0;
        while (x > 0){
            if (revInt > MAX/10 || revInt < MIN/10){
                return 0;
            }
            revInt = revInt * 10 + x % 10;
            x = x /10;
        }
        
        return revInt*isNegative;
    }
};