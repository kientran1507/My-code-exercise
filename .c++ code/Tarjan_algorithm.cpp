#include <bits/stdc++.h>

using namespace std;

const int N = 100006;
int n, m;
vector<int> A[N];
int low[N], num[N];
bool visited[N];
int t;
int bridges = 0;
int articulationPoints = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int u, int pu) {
    t++;
    num[u] = t;
    low[u] = num[u];
    visited[u] = true;

    int children = 0;

    for (int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if (v == pu) continue;
        if (visited[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if ((pu > 0 && low[v] >= num[u]) || (pu == 0 && children > 0)) {
                articulationPoints++;
            }
            if (low[v] > num[u]) {
                bridges++;
            }
        }
    }
}

void init() {
    for (int v = 1; v <= n; v++) {
        visited[v] = false;
    }
}

void solve() {
    init();
    t = 0;
    bridges = 0;
    articulationPoints = 0;
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u, -1);
        }
    }
}

int main() {
    input();
    solve();
    cout << articulationPoints << " " << bridges << endl;
    return 0;
}
