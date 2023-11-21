#include <stdio.h>
#define N 10000

int n,m;
int T[N][N];

void input(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &T[i][j]);
        }
    }
}
int main(void){
    input();
    int blackColumns = 0;
    for (int j = 0; j < m; j++) {
        int isBlackColumn = 1; // Assume the column is black

        // Check each element in the column
        for (int i = 0; i < n; i++) {
            if (T[i][j] == 0) {
                isBlackColumn = 0; // If any element is 0, the column is not black
                break;
            }
        }

        // Increment the count if the column is black
        if (isBlackColumn) {
            blackColumns++;
        }
    }
    // Print the result
    printf("%d\n", blackColumns);

    return 0;
}
