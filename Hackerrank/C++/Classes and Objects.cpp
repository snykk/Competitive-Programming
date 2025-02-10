#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
// Define the Student class
class Student {
private:
    vector<int> scores; // Instance variable to hold student's exam scores

public:
    // Function to read scores from input
    void input() {
        int score;
        for (int i = 0; i < 5; i++) { // Assuming there are always 5 scores per student
            cin >> score;
            scores.push_back(score);
        }
    }

    // Function to calculate the total score
    int calculateTotalScore() {
        int total = 0;
        for (int score : scores) {
            total += score;
        }
        return total;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
