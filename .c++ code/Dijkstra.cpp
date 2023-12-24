#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const int N = 1e5 + 1;

struct Arc{
    int node;
    int w;
    Arc(int _node, int _w){
        node = _node;
        w = _w;
    }
};

vector<Arc> A[N];
int n, m;
bool visited[N];
int d[N];
int s, t;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    } 
    cin >> s >> t;
}

int selectMin(set<int>& S){
    int minD = INF;
    int sel_u = -1;
    for(set<int>::iterator p = S.begin(); p != S.end(); p++){
        int u = *p;
        if(d[u] < minD){
            minD = d[u];
            sel_u = u;
        }
    }
    return sel_u;
}

void dijkstra(){
    for(int v = 1; v <= n; v++) d[v] = INF;
    for(int i = 0; i < A[s].size(); i++){
        Arc a = A[s][i];
        d[a.node] = a.w;
    }
    set<int> S; // tap cac dinh chua tim duoc duong di ngan nhat
    for(int v = 1; v <= n; v++) if(v != s) S.insert(v);
    while(S.size() > 0){
        int u = selectMin(S);
        S.erase(u);
        //cout << "found shortest length from " <<  s << " to " << u << " = " << d[u] << endl;
        if (u == t) {
            cout << d[u] << endl;
            break;
        }
        for(int i = 0; i < A[u].size(); i++){
            int v = A[u][i].node;
            int w = A[u][i].w;
            if(S.find(v) != S.end() && d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
}

int main() {
    input();
    dijkstra();
    return 0;
}