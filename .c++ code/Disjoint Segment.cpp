#include <bits/stdc++.h>

using namespace std;

// Structure to represent a segment
struct Segment {
    int start;
    int end;
};

int n; // Number of segments  
int sol; // Number of segments in the solution found
vector<Segment> X; // Segment

// Function to compare segments based on their right endpoints
bool compareSegments(const Segment& a, const Segment& b) {
    return a.end < b.end;
}

// Function to input from user
void input(){
    // Read the number of segments
    cin >> n;
    X.resize(n);  // Resize the vector based on the value of n
    // Read the segments
    for (int i = 0; i < n; ++i) {
        cin >> X[i].start >> X[i].end;
    }
}

// Main function
int main(){
    input();
    // Sort segments by their right endpoints
    sort(X.begin(), X.end(), compareSegments);

    int prevRightEndpoint = -1;
    for (int i = 0; i < n; ++i) {
        if (prevRightEndpoint == -1 || X[i].start > prevRightEndpoint) {
            sol++;
            prevRightEndpoint = X[i].end;
        }
    }
    cout << sol << endl;
    return 0;
}
