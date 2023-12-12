#include <stdio.h>

void insertionSort(int A[], int N){
    // Index tu 0 den N-1
    for (int i = 0; i < N; i++){
        int last = A[i];
        int j = i;
        while (j > 0 && A[j-1] > last){
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
    }
}

int main(void){
    int n;
    int A[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}