#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Define necessary preprocessor macros
#define INF 100000000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define DIFF(x, y) ((x) - (y))

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    int maxVal = -INF;
    int minVal = INF;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }
    
    cout << "Result = " << DIFF(maxVal, minVal) << endl;
    
    return 0;
}
