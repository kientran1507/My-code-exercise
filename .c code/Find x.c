#include <stdio.h>

#define MAX_N 1000

int n, M;
int a[MAX_N];
int x[MAX_N];
int max = 0;
int solution_found = 0; 

void input() {
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void solve(int index, int remaining) {
    int mul = 1;
    if (index == n) {
        if (remaining == 0) {
            for (int i = 0; i < n; i++) {
                //printf("%d ", x[i]);
                mul *= x[i];
            }
            if (mul > max) max = mul;
            solution_found = 1;
        }
        return;
    }

    for (int i = 0; i <= remaining / a[index]; i++) {
        x[index] = i;
        solve(index + 1, remaining - a[index] * i);
    }
}

int main() {
    input();
    solve(0, M);
    if (solution_found && max > 0) {
        printf("%d\n", max);
    } else {
        printf("None\n");
    }
    return 0;
}
