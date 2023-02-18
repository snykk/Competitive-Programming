class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<string> s;
        s.push("(");
        stack<int> counts;
        counts.push(1);

        while (!s.empty()) {
            string current = s.top();
            s.pop();
            int count = counts.top();
            counts.pop();
            if (current.size() == n * 2) {
                result.push_back(current);
                continue;
            } 

            if (count < n) {
                s.push(current + "(");
                counts.push(count + 1);
            }
            if (current.size() - count < count) {
                s.push(current + ")");
                counts.push(count);
            }
        }

        return result;
    }

};
