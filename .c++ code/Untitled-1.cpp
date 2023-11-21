#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[N];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i] represents the maximum sum of a subsequence ending at index i
    int dp[N] = {0};

    // Base case: The maximum sum of a subsequence ending at index 0 is a[0]
    dp[0] = max(0, a[0]);

    // Iterate through the array to fill the dp array
    for (int i = 1; i < n; ++i) {
        // The maximum sum of a subsequence ending at index i is either
        // the current element a[i] or the sum of the previous subsequence ending at i-1 and a[i]
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }

    // Find the maximum value in the dp array, which represents the highest subsequence weight
    int maxWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] % 2 == 0)
        maxWeight = max(maxWeight, dp[i]);
    }

    cout << maxWeight << endl;

    return 0;
}
