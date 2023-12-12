#include <stdio.h>

void selectionSort(int A[], int N){
    // Index tu 0 den N-1
    for (int k = 0; k < N; k++){
        int min = k;
        for (int j = k+1; j < N; j++){
            if (A[min] > A[j]) min = j;
        }   
        int tmp = A[min];
        A[min] = A[k];
        A[k] = tmp;
    }
}

int main(void){
    int n;
    int A[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    selectionSort(A, n);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}