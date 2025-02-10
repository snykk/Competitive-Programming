#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m, temp;
    vector<int>::iterator low;
    vector<int> v;
    cin >> n;
    while (n--) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> m;
    while (m--) {
        cin >> temp;
        low = lower_bound (v.begin(), v.end(), temp);
        if (temp < v[low -v.begin()])
            cout << "No " << (low -v.begin()) + 1 << endl;
        else 
            cout << "Yes " << (low - v.begin()) + 1 << endl;
    }
    return 0;
}
