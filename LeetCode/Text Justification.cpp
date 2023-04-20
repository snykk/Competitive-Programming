class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size(), i = 0;
        while (i < n) {
            // calculate the number of words to fit in the current line
            int len = words[i].length(), j = i + 1;
            while (j < n && len + 1 + words[j].length() <= maxWidth) {
                len += 1 + words[j].length();
                j++;
            }
            // calculate the number of spaces between words
            int spaces = maxWidth - len;
            int gaps = j - i - 1;
            string line = words[i];
            // for the last line or a line with only one word, left-justify it
            if (gaps == 0 || j == n) {
                for (int k = i + 1; k < j; k++) {
                    line += ' ' + words[k];
                }
                line += string(spaces, ' ');
            } else {
                // distribute the spaces as evenly as possible
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;
                for (int k = i + 1; k < j; k++) {
                    line += string(spacesPerGap, ' ');
                    if (extraSpaces > 0) {
                        line += ' ';
                        extraSpaces--;
                    }
                    line += ' ' + words[k];
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
