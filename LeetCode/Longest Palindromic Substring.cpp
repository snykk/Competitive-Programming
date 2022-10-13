class Solution {
public:
    string longestPalindrome(string str) {
        vector<int> vec1,vec2;
        int length = str.length();
        vec1.assign(length,0), vec2.assign(length,0);

        for(int i = 0, l = 0, r = -1; i < length; i++) {
            int j = (i > r) ? 1 : min(vec1[l+r-i], r-i+1);

            while(0<=i-j and i+j<length and str[i-j]==str[i+j]) j++;
            vec1[i] = j--;
            if(i+j > r) {
                l = i-j;
                r = i+j;
            }
        }

        for(int i = 0, l = 0,r = -1;i < length; i++) {
            int j = (i > r) ? 0 : min(vec2[l+r-i+1], r-i+1);
            while(0 <= i-j-1 and i+j < length and str[i-j-1] == str[i+j]) j++;

            vec2[i] = j--;

            if(i+j > r) {
                l = i-j-1;
                r = i+j;
            }
        }

        int it =0 , pos = -1, check = 0;
        for(int i = 0; i < length; i++) {
            if(2*vec1[i]-1 > it){
                it = 2*vec1[i]-1;
                pos = i;
                check = 0;
            } 

            if(2*vec2[i] >= it) {
                pos = i;
                it = 2*vec2[i];
                check = 1;
            }
        }

        if(check) {
            return str.substr(pos-vec2[pos], it);
        } 

        return str.substr(pos-vec1[pos]+1, it);
    }
};
