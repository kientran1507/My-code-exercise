#include <stdio.h>

int n;
int x[10];
void solution(){
    for (int i=1; i<=n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

int check(int v, int k){
    return 1;
}

void Try(int k){
    for (int v=0; v<=1; v++){
        if (check(v,k)){
            x[k]=v;
            if(k==n) solution();
            else Try(k+1);
        }
    }
}

int main(){
    scanf("%d", &n); 
    Try(1);
    return 0;
}