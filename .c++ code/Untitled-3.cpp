#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a segment
struct Segment {
    int start;
    int end;
};

// Function to compare segments based on their right endpoints
bool compareSegments(const Segment& a, const Segment& b) {
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n; // Read the number of segments

    std::vector<Segment> X(n);

    // Read the segments
    for (int i = 0; i < n; ++i) {
        std::cin >> X[i].start >> X[i].end;
    }

    // Sort segments by their right endpoints
    std::sort(X.begin(), X.end(), compareSegments);

    std::vector<Segment> result;
    int prevRightEndpoint = -1;

    for (int i = 0; i < n; ++i) {
        if (prevRightEndpoint == -1 || X[i].start > prevRightEndpoint) {
            result.push_back(X[i]);
            prevRightEndpoint = X[i].end;
        }
    }

    std::cout << "Largest subset of non-intersecting segments: ";
    for (const Segment& segment : result) {
        std::cout << "(" << segment.start << ", " << segment.end << ") ";
    }
    std::cout << std::endl;

    return 0;
}
