class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to a set for O(1) lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return {};
        }

        // Preprocessing: Create a map of all possible intermediate words
        unordered_map<string, vector<string>> wordMap;
        for (const string& word : wordSet) {
            for (int i = 0; i < word.size(); ++i) {
                string intermediate = word.substr(0, i) + '*' + word.substr(i + 1);
                wordMap[intermediate].push_back(word);
            }
        }

        // BFS to find the shortest path
        queue<pair<string, int>> q; // {word, level}
        q.push({beginWord, 1});
        unordered_map<string, int> visited = {{beginWord, 1}};
        unordered_map<string, vector<string>> parents;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            string currentWord = current.first;
            int level = current.second;

            for (int i = 0; i < currentWord.size(); ++i) {
                string intermediate = currentWord.substr(0, i) + '*' + currentWord.substr(i + 1);
                for (const string& word : wordMap[intermediate]) {
                    if (visited.find(word) == visited.end()) {
                        visited[word] = level + 1;
                        q.push({word, level + 1});
                    }
                    if (visited[word] == level + 1) {
                        parents[word].push_back(currentWord);
                    }
                }
            }
        }

        // DFS to reconstruct all the shortest paths
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, result);

        // Reverse each path to get the correct order
        for (vector<string>& p : result) {
            reverse(p.begin(), p.end());
        }

        return result;
    }

private:
    void dfs(const string& currentWord, const string& beginWord,
             unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& result) {
        if (currentWord == beginWord) {
            result.push_back(path);
            return;
        }
        for (const string& parent : parents[currentWord]) {
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back(); // Backtrack
        }
    }
};
