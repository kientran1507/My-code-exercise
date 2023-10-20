#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
const int MAX_M = 20;

int n, M;
int x[MAX_N];
int T = 0;
vector<int> a; // Store the coefficients a₁, a₂, ..., aₙ

bool check(int v, int k) {
    if (k < n) {
        return true;
    } else {
        return T + a[k - 1] * v == M;
    }
}

int Try(int k) {
    int M0 = M - T - (n - k);
    int count = 0;
    for (int v = 1; v <= M0; ++v) {
        if (check(v, k)) {
            x[k] = v;
            T += a[k - 1] * x[k];
            if (k == n) {
                int sum = 0;
                for (int i = 1; i <= n; ++i) {
                    sum += a[i - 1] * x[i];
                }
                if (sum == M) {
                   count += 1;
                }
            } else {
                count += Try(k + 1);
            }
            T -= a[k - 1] * x[k];
        }
    }
    return count;
}

int main() {
    cin >> n >> M;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n >= 1 && n <= MAX_N && M >= 1 && M <= MAX_M) {
        int solutionCount = Try(1);
        cout << solutionCount;
    }

    return 0;
}
