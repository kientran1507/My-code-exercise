#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

int n,m;
vector<int> A[N];
int low[N], num[N];
stack<int> scc;
bool inStack[N];
int nbscc;
int t;

void input(){
    cin >> n >> m;
    for(int k = 1; k <= m; k++){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
    }
}

void dfs(int u, int pu){
    t++;
    num[u] = t;
    low[u] = t;
    scc.push(u);
    inStack[u] = true;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(num[v] > 0){ // back-arc(u, v)
            if(inStack[v]) low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if(num[u]==low[u]){ // strongly connected component
        while(true){
            int x = scc.top();
            scc.pop();
            inStack[x] = false;
            if(x == u) break;
        }
        cout << endl;
        nbscc++;
    }
}

void init(){
    for(int v = 1; v <= n ; v++){
        num[v] = -1;
        inStack[v] = false;
    }
}

void solve(){
    init();
    t = 0;
    nbscc = 0;
    for(int u = 1; u <= n; u++){
        if(num[u]==-1){
            dfs(u, -1);
        }
    }
}

int main(){
    input();
    solve();
    cout << nbscc;
}