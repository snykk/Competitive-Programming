class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (n == INT_MIN) {
            return 1.0 / myPow(x, INT_MAX) / x;
        }
        
        if (n < 0) {
            return 1.0 / myPow(x, static_cast<unsigned int>(-n));
        } 
        
        if (n % 2 == 0) {
            double temp = myPow(x, n / 2);
            return temp * temp;
        } 
        
        double temp = myPow(x, (n - 1) / 2);
        return x * temp * temp;
    }
};
