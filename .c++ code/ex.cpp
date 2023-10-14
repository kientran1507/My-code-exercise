#include <bits/stdc++.h>

using namespace std;

#define N 100 
int n, K, Q;
int d[N];
int C[N][N];
int Y[N];
int X[N];
int load[N];
int nbSegments;
int f;
int fmin;
bool visited[N];

void input(){
    cin >> n >> K >> Q;
    for(int i=1; i<=n, i++) cin >> d[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> C[i][j];
        }
    }
}

bool checkY(int v, int k){
    if (visited[v]) return false;
    if (load[k]+d[v]>Q) return false;
    return true;
}

int TryY(int k){
for (int v=Y[k-1]+1; v<=n-K+k; v++){
    if (checkY(v,k)){
        Y[k]=v;
        visited[v]=true;
        f=f+C[0][v];
        load[k]+=d[v];
        nbSegments+=1;
    if (k==K){
        TryX(Y[1],1);
    } else {
        TryY(k+1);
    }
    visited[v]=false;
    f=f-C[0][v];
    load[k]-=d[v];
    nbSegments=nbSegments-1;  
}
}
TryX
for (v=0, v<N, v++)
if check X(v,i,k) then
    X[i]=v;
    visited[v]=true
    f=f+C[i,X[i]]
    load[k]+=d[0]
    nbsegment=nbsegment+1
    if v=0 then 
        if k=K then solution
        else try X(Y[k+1],k+1)
    else try X(v,k)
        visited[v]=false
        f=f-C[i,X[i]]
        load[k]=load[k]-d[v]
        nbsegment=nbsegment-1
