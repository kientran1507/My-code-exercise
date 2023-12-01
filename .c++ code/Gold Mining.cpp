#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int a[N], F[N];
int n, L1, L2, ans;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solveN2(){
    F[1] = a[1];
    ans = F[1];
    for (int i = 2; i <= n; i++){
        F[i] = a[i];
        for (int d = L1; d <= L2; d++){
            int j = i - d;
            if (j >= 1 && F[i] < F[j] + a[i]){
                F[i] = F[j] + a[i];
            }
        }
        ans = max(ans, F[i]);
    }
    cout << ans;
}

int main(void){
    input();
    solveN2();
    return 0;
}