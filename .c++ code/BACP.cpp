#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 16;  // Maximum number of courses
const int MAX_M = 5;   // Maximum number of periods

int N, M;
int credits[MAX_N];
int prerequisites[MAX_N][MAX_N];
int periods[MAX_M];
int maxLoad = INT_MAX;  // Initialize maxLoad with a large value

bool isFeasible(int course, int period) {
    // Check if prerequisites of the course have been satisfied
    for (int i = 0; i < N; i++) {
        if (prerequisites[course][i] == 1 && periods[i] < period) {
            return false;
        }
    }
    return true;
}

void backtrack(int course) {
    if (course == N) {
        // All courses assigned, update maxLoad
        int currentMaxLoad = *max_element(periods, periods + M);
        maxLoad = min(maxLoad, currentMaxLoad);
        return;
    }

    for (int period = 0; period < M; period++) {
        if (periods[period] + credits[course] < maxLoad && isFeasible(course, period)) {
            // Assign the course to the period
            periods[period] += credits[course];
            backtrack(course + 1);
            // Undo the assignment (backtrack)
            periods[period] -= credits[course];
        }
    }
}

int main() {
    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++) {
        cin >> credits[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> prerequisites[i][j];
        }
    }

    // Initialize periods
    fill(periods, periods + M, 0);

    // Start the backtracking process
    backtrack(0);

    cout << maxLoad << endl;

    return 0;
}
