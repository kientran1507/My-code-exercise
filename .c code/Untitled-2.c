#include <stdio.h>

int n;
int a[100];
int sum;

int main(void){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%d", sum);
}
