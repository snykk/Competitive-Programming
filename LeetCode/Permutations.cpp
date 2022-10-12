class Solution {
public:
  void helperRec(vector<int> &num, int start, vector<vector<int>> &result)  {
    if (start >= num.size()) {
        // one permutation instance
        result.push_back(num);
        return;
    }
    
    for (int i=start; i < num.size(); i++) {
        swap(num[start], num[i]);
        helperRec(num, start + 1, result);
        // reset
        swap(num[start], num[i]);
    }
  }

  vector<vector<int>> permute(vector<int> &num) {
    vector<vector<int>> result;
    helperRec(num, 0, result);

    return result;
  }
};