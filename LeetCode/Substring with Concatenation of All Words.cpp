class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;

        if (s.length() < total_len) return result;

        // Create a frequency map for words
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        // Check each possible starting position
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            unordered_map<string, int> window_count;

            while (right + word_len <= s.length()) {
                string word = s.substr(right, word_len);
                right += word_len;

                // If the word is part of `words`
                if (word_count.find(word) != word_count.end()) {
                    window_count[word]++;

                    // If frequency exceeds the expected, slide the window
                    while (window_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        left += word_len;
                    }

                    // Check if we have a valid window
                    if (right - left == total_len) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if an invalid word is found
                    window_count.clear();
                    left = right;
                }
            }
        }

        return result;
    }
};