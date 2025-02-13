#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, map<string, string>> hrml;
    vector<string> tag_stack;
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        line.erase(remove(line.begin(), line.end(), '='), line.end());

        if (line[1] == '/') { 
            tag_stack.pop_back();
        } else {
            stringstream ss(line);
            string tag, attr, value;
            ss >> tag;
            tag = tag.substr(1);
            if (tag.back() == '>') tag.pop_back();

            string prefix = tag_stack.empty() ? tag : tag_stack.back() + "." + tag;
            tag_stack.push_back(prefix);

            while (ss >> attr >> value) {
                if (value.back() == '>') value.pop_back();
                hrml[prefix][attr] = value;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        size_t pos = query.find('~');

        string tag_path = query.substr(0, pos);
        string attr = query.substr(pos + 1);

        if (hrml.find(tag_path) != hrml.end() && hrml[tag_path].find(attr) != hrml[tag_path].end()) {
            cout << hrml[tag_path][attr] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
