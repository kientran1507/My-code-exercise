#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int m, n;
vector<int> T[N];
bool conflict[N][N];
int x[N];
int load[N];
int res;

void input() {
    cin >> m >> n;
    for (int t = 1; t <= m; t++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int c;
            cin >> c;
            T[c].push_back(t);
        }
    }

    int K;
    cin >> K;
    for (int k = 1; k <= K; k++) {
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}

bool check(int t, int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == t && conflict[i][k]) {
            return false;
        }
    }
    return true;
}

void Try(int k) {
    for (int i = 0; i < T[k].size(); i++) {
        int t = T[k][i];
        if (check(t, k)) {
            x[k] = t;
            load[t] += 1;
            if (k == n) {
                int maxLoad = *max_element(load + 1, load + m + 1);
                res = min(res, maxLoad);
            } else {
                if (load[t] < res) {
                    Try(k + 1);
                }
            }
            load[t] -= 1;
        }
    }
}

int main() {
    input();
    for (int t = 1; t <= m; t++) {
        load[t] = 0;
    }
    res = 1e9;
    Try(1);
    cout << res;
    return 0;
}
