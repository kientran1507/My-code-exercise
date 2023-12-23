#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

struct Edge{
    int u, v;
    int w;
    Edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

// data structure for input graph
int N, M;
vector<Edge> E;

// data structure for disjoint-set
int r[MAX]; // r[v] is the rank of set v
int p[MAX]; // p[v] is parent of v
long long rs;

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

void unify(int x, int y){
    if (r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
    }
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

bool cmp(Edge& e1, Edge& e2){
    return e1.w < e2.w;
}

void solve(vector<Edge>& T){
    sort(E.begin(), E.end(), cmp);
    for(int x = 1; x <= N; x++){
        makeSet(x);
    }
    for(int i = 0; i < M; i++){
        // conside edge(u[i], v[i])
        int ru = find(E[i].u);
        int rv = find(E[i].v);
        if(ru != rv){
            unify(ru, rv);
            T.push_back(E[i]);
            rs += E[i].w;
            if(T.size() == N-1) break;
        }
    }
}

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w; // w is the weight of (u,v)
        E.push_back(Edge(u, v, w));
    }
}

int main(){
    input();
    vector<Edge> T;
    solve(T);
    int weight = 0;
    for(int i = 0; i < T.size(); i++)
        //cout << T[i].u << "," << T[i].v << "," << T[i].w << endl;
        weight += T[i].w;
    cout << weight << endl;
}