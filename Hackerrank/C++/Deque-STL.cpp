#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to print the maximum in every contiguous subarray of size K
void printMaxInSubarrays(vector<int> arr, int n, int k) {
    deque<int> dq; // Deque to store indices of useful elements

    // Process the first K elements (initial window)
    for (int i = 0; i < k; i++) {
        // Remove elements that are smaller than the current element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        // Push current element index into the deque
        dq.push_back(i);
    }

    // Process the rest of the elements
    for (int i = k; i < n; i++) {
        // Print the maximum of the previous window
        cout << arr[dq.front()] << " ";

        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove elements that are smaller than the current element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // Print the maximum of the last window
    cout << arr[dq.front()] << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        printMaxInSubarrays(arr, N, K);
    }

    return 0;
}