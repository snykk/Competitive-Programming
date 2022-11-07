class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if(digits.size()==0) return result;

        return divideAndConquer(digits, result, letters);
    }
    
    vector<string> divideAndConquer(string digits, vector< string> result, vector<string> &letters){
        if (digits.size() >= 2){
            int m=digits.size()/2;
            auto left=divideAndConquer(digits.substr(0, m), result, letters);
            auto right=divideAndConquer(digits.substr(m, digits.size()), result, letters);
            if (left.size() !=0 && right.size() != 0){
                for (auto l:left) {
                    for (auto r:right) {
                        result.push_back(l+r);
                    }
                }
            } else if (left.size() == 0)
                for(auto r:right) result.push_back(r);
            else
                for(auto l: left) result.push_back(l);

            return result;
        }else{
            auto &letter=letters[stoi(digits)];
            vector<string> res;

            for(auto let:letter) res.push_back(string(1,let));

            return res;
        }
    }
};