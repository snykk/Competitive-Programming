class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) // If endWord is not in wordList, return 0
            return 0;

        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string currentWord = q.front();
                q.pop();
                if (currentWord == endWord)
                    return ladderLength;

                // Generate all possible transformations of the current word
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar)
                            continue;

                        currentWord[j] = c;
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Mark as visited
                        }
                    }
                    currentWord[j] = originalChar; // Restore the original character
                }
            }
            ladderLength++;
        }

        return 0; // No transformation sequence exists
    }
};