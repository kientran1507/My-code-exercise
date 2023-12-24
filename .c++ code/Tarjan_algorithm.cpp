#include <bits/stdc++.h>

using namespace std;

const int N = 100006;
int n, m;
vector<int> A[N];
int low[N], num[N];
bool visited[N];
int t;
vector<pair<int, int>> bridges;
int a; // articulation points

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

void dfs(int s, int ps) {
    t++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;

    for (int i = 0; i < A[s].size(); i++) {
        int v = A[s][i];
        if (v == ps) continue;
        if (visited[v]) {
            low[s] = min(low[s], num[v]);
        } else {
            dfs(v, s);
            low[s] = min(low[s], low[v]);
            if (low[v] > num[s]){
                // discovered a bridge (s, v)
                bridges.push_back(make_pair(s, v));
            }
            if (ps > -1 && low[v] >= num[s]){
                // discovered an articulation point
                a++;
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
    for(int s = 1; s <= n; s++){
        if (!visited[s]) {
            dfs(s, -1);
        }
    }
    //cout << "bridges = ";
    //for (int i = 0; i < bridges.size(); i++){
        //cout << "(" << bridges[i].first << "," << bridges[i].second << ")";
    //}
    cout << a << " " << bridges.size() << endl;
}

int main() {
    input();
    solve();

}
