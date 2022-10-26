class Solution {
public:
    // [Solution 1] smart solution little bit effort
    string intToRoman(int num) {
        string result = "";
        vector<int> vecInt = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> vecStr = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int lengthVecInt = vecInt.size();
        
        for (int i = 0; i < lengthVecInt; i++) {
            if(vecInt[i] <= num) {
                result += vecStr[i];
                num -= vecInt[i];
                i--;
            }
        }

        return result;
    }

    // [Solution 2] cheap memory and runtime but more extra effort
    string intToRoman2(int num) {
        string result = "";
    
        while (num != 0) {
            if (num >= 1000) {
                result += 'M';
                num -= 1000;
            } else if (num >= 500 && num < 900) {
                result += 'D';
                num -= 500;
            } else if (num >= 100 && num < 400) {
                result += 'C';
                num -= 100;
            } else if (num >= 50 && num < 90) {
                result += 'L';
                num -= 50;
            } else if (num >= 10 && num < 40) {
                result += 'X';
                num -= 10;
            } else if (num >= 5 && num < 9) {
                result += 'V';
                num -= 5;
            } else if (num >= 1 && num < 4) {
                result += 'I';
                num -= 1;
            } else if (num == 4) {
                result += "IV", num -= 4;
            } else if (num == 9) {
                result += "IX", num -= 9;
            } else if ((num >= 40 || num >= 90) && num < 100) {
                result += 'X';
                if (num >= 90) result += 'C', num -= 90;
                else result += 'L', num -= 40;
            }  else if ((num >= 400 || num >= 900) && num < 1000) {
                result += 'C';
                if (num >= 900) result += 'M', num -= 900;
                else result += 'D', num -= 400;
            }
        }

        return result;
    }
};