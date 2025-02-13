#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Workshop {
    int start_time;
    int duration;
    int end_time;

    // Constructor to initialize workshop details
    Workshop(int start, int dur) {
        start_time = start;
        duration = dur;
        end_time = start + dur;
    }
};

struct Available_Workshops {
    int n;
    vector<Workshop> workshops;

    // Constructor to initialize Available_Workshops
    Available_Workshops(int num) : n(num) {
        workshops.reserve(num);
    }
};

// Initialize Available_Workshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* availableWorkshops = new Available_Workshops(n);

    for (int i = 0; i < n; i++) {
        availableWorkshops->workshops.emplace_back(start_time[i], duration[i]);
    }

    return availableWorkshops;
}

// Calculate the maximum number of workshops the student can attend
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    // Sort workshops by end time (Greedy Approach)
    sort(ptr->workshops.begin(), ptr->workshops.end(), [](const Workshop &a, const Workshop &b) {
        return a.end_time < b.end_time;
    });

    int maxWorkshops = 0, lastEndTime = 0;

    for (const auto &workshop : ptr->workshops) {
        if (workshop.start_time >= lastEndTime) {
            maxWorkshops++;
            lastEndTime = workshop.end_time;  // Update last attended workshop's end time
        }
    }

    return maxWorkshops;
}

int main() {
    int n;
    cin >> n;
    int start_time[n], duration[n];

    for (int i = 0; i < n; i++) cin >> start_time[i];
    for (int i = 0; i < n; i++) cin >> duration[i];

    Available_Workshops* workshops = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(workshops) << endl;

    delete workshops; // Free allocated memory
    return 0;
}
