#include <stdio.h>
#include <string.h>
#define MAX 1000
#define MOD 1000000007

long long M[MAX][MAX];

long long C(long long k, long long n){
    if (k == 0 || k == n) {
        M[k][n] = 1;
    } else if (M[k][n] == 0) {
        M[k][n] = (C(k, n-1) + C(k-1, n-1)) % MOD;
    }
    return M[k][n];
}

int main(){
    long long k, n;
    memset(M, 0, sizeof(M));

    scanf("%lld %lld", &k, &n);
    printf("%lld\n", C(k, n));

    return 0;
}
