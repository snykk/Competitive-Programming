class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        // Iterate through each string in the input
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string
            anagramMap[sortedStr].push_back(str); // Group by the sorted string
        }

        // Prepare the result from the map
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }

};