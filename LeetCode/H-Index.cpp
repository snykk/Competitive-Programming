class Solution {
    public:
        // int hIndex(vector<int>& citations) {
        //     stable_sort(citations.begin(), citations.end(), greater<>());
    
        //     int index = 1;
        //     for (int citation : citations) {
        //         if (citation < index) break;
        //         index++;
        //     }
    
        //     return --index;
        // }
    
        // more readable
        int hIndex(vector<int>& citations) {
            sort(citations.rbegin(), citations.rend());
            int h = 0;
            for (int i = 0; i < citations.size(); i++) {
                if (citations[i] >= i + 1) {
                    h = i + 1;
                } else {
                    break;
                }
            }
            return h;
        }
    };