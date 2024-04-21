class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        
        // Nested function to perform backtracking
        function<void(int)> backtrack = [&](int start) {
            if (parts.size() == 4 && start == s.length()) {
                result.push_back(join(parts, "."));
                return;
            }

            for (int length = 1; length <= 3 && start + length <= s.length(); ++length) {
                string segment = s.substr(start, length);
                if (isValidSegment(segment)) {
                    parts.push_back(segment);
                    backtrack(start + length);
                    parts.pop_back(); // Backtrack
                }
            }
        };

        backtrack(0); // Start the backtracking process

        return result;
    }

private:
    bool isValidSegment(const string& segment) {
        if (segment.length() > 1 && segment[0] == '0') {
            return false; // Leading zeros are not allowed
        }
        int value = stoi(segment);
        return value >= 0 && value <= 255;
    }

    string join(const vector<string>& parts, const string& delimiter) {
        string result;
        for (int i = 0; i < parts.size(); ++i) {
            result += parts[i];
            if (i < parts.size() - 1) {
                result += delimiter;
            }
        }
        return result;
    }
};
