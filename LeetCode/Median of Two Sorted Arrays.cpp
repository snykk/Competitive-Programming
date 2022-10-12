class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merged two vector
        vector<int> mergedVec;
        mergedVec.reserve( nums1.size() + nums2.size() ); // preallocate memory
        mergedVec.insert( mergedVec.end(), nums1.begin(), nums1.end() );
        mergedVec.insert( mergedVec.end(), nums2.begin(), nums2.end() );
        
        // sorting vector value
        sort(mergedVec.begin(), mergedVec.end());
        int n = mergedVec.size();
        int middle = n/2;
        double result;
        
        // get median
        if (n%2 == 0) result = (mergedVec[middle] + mergedVec[middle-1])/2.0;
            
        else result = mergedVec[middle];
                
        return result;
    }
};