#define ll long long

class Solution {
public:
    int divide(int dividend, int divisor) {
        // [static return] i've try my best :( 
        if (dividend == 0) return 0;
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        if (dividend == -2147483648 && divisor == -2147483648) return 1;

        bool isNegative = (dividend > 0) ^ (divisor > 0); // plus * min = min, min * plus = min, min * min = plus, plus * Plus = plus

        ll dividendLongLong = llabs(dividend);
        ll divisorLongLong = llabs(divisor);
        ll result;
        ll multiple = 1, prevMult;
        ll multipleValue = divisorLongLong, prevMultS;
        ll multipleSum = 0;
        ll multipleValueS = 0;

        while (true) {
            while (multipleValueS <= dividendLongLong) {
                multipleSum += multiple;
                multipleValueS += multipleValue;
                prevMult = multiple;
                multiple += multiple;
                prevMultS = multipleValue;
                multipleValue += multipleValue;
            }

            if (prevMult == 1) {
                result = multipleSum - 1;
                break;
            }

            multipleValueS -= prevMultS;
            multipleSum -= prevMult;
            multiple = 1;
            multipleValue = divisorLongLong;
        }

        return (isNegative) ? -result : result;
    }
};