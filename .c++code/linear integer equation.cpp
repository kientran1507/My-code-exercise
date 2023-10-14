#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10;
const int MAX_M = 20;

int n, M;
int x[MAX_N];
int T = 0;

bool check(int v, int k){
    if (k < n){
        return true;
    } else {
        return T + v == M;
    }
}

void Try(int k) {

    int M0 = M - T - (n - k);
    for (int v = 1; v <= M0; ++v) {
        if (check(v,k)){
            x[k] = v;
            T += x[k];
            if (k == n) {
                for (int i = 1; i < n+1; ++i) {
                    cout << x[i] << " ";
                }
                cout << endl;
            }
            else Try(k + 1);
            T -= x[k];
        }
    }
}

int main() {
    cin >> n >> M;
    
    if (n >= 2 && n <= MAX_N && M >= 1 && M <= MAX_M) {
        Try(1);
    }

    return 0;
}
