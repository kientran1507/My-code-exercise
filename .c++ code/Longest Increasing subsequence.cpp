#include <bits/stdc++.h>
#define N 10000
using namespace std;

int n;
int a[N];
int dp[N];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

int main() {
    input();
    int maxLength = 1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
        maxLength = max(maxLength, dp[i]);
    }
    cout << maxLength << endl;
    return 0;
}
