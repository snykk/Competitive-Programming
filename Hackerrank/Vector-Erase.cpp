#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int> vec;
    int n, item, x, a,b;
    cin >> n;
    while (n--){
        cin >> item;
        vec.push_back(item);
    }
    cin >> x;
    vec.erase(vec.begin()+(x-1));
    cin >> a >> b;
    vec.erase(vec.begin() + (a-1), vec.begin() + (b-1));
    cout << vec.size() << endl;
    for (auto it:vec) 
        cout << it << " ";
    return 0;
}
