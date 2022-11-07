class Solution {
public:
    bool check(vector<char> line)
    {
        sort(line.begin(), line.end()); // '5','3','.','.','7','.','.','.','.' ==>  '.', '.', '.', '.', '.', '.', '3', '5', '7'
        for (int i = line.size()-1; i > 0 ; i--) {
            if (line[i] == '.') break;

            if (line[i] == line[i-1]) return false;
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (!check(board[i])) return false;
        }
        
        vector<char> temp;
        
        for (int i = 0; i < board.size(); i++) {
            temp.clear();
            for (int j = 0; j < board.size(); j++) temp.push_back(board[j][i]);

            if (!check(temp)) return false;
        }
        
        for (int i = 0; i < board.size(); i+=3 ) {
            for (int j = 0; j < board.size(); j+=3) {
                temp.clear();

                for (int l = 0; l < 3; ++l) {
                    for (int k = 0; k < 3; k++) temp.push_back(board[i+l][j+k]);
                }

                if (!check(temp)) return false;
            }
        }

        return true; 
    }
};