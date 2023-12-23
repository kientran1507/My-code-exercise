#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100001

struct Edge{
    int node;
    int w;
    Edge(int _node, int _w){
        node = _node;
        w = _w;
    }
};
int N;
vector<Edge>A[MAX_N]; // A[v][i] is the i.th adjacent node to v
int d[MAX_N]; // d[v] is the distance from the source node to v in BFS
int p[MAX_N]; // p[v] is the parent of v by BFS

void input(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        A[v].push_back(Edge(u, w));
        A[u].push_back(Edge(v, w));
    }
}

void init(){
    for(int v = 1; v <= N-1; v++){
        d[v] = -1;
        p[v] = -1;
    }
}

void BFS(int u){
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i++){
            Edge e = A[v][i];
            int x = e.node;
            if(p[v] == x) continue;
            int w = e.w;
            Q.push(x);
            d[x] = d[v] + w;
            p[x] = v;           
        }
    }
}

int findMax(){
    int max_d = -1;
    int u = -1;
    for(int v = 1; v <= N; v++){
        if(max_d < d[v]){
            max_d = d[v];
            u = v;
        }
    }
    return u;
}

void solve(){
    init();
    BFS(1);
    int u = findMax();
    init();
    BFS(u);
    u = findMax();
    cout << d[u];
}

int main(){
    input();
    solve();
}