#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> memo;

int longestCommonSubsequence(vector<int>& X, vector<int>& Y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (memo[n][m] != -1) {
        return memo[n][m];
    }

    if (X[n - 1] == Y[m - 1]) {
        memo[n][m] = 1 + longestCommonSubsequence(X, Y, n - 1, m - 1);
    } else {
        memo[n][m] = max(longestCommonSubsequence(X, Y, n - 1, m), longestCommonSubsequence(X, Y, n, m - 1));
    }

    return memo[n][m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> X(n);
    vector<int> Y(m);

    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> Y[i];
    }

    // Initialize memoization table with -1
    memo.assign(n + 1, vector<int>(m + 1, -1));

    int result = longestCommonSubsequence(X, Y, n, m);
    cout << result << "\n";

    return 0;
}
