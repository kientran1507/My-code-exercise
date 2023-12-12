#include <stdio.h>

void bubbleSort(int A[], int N){
    // Index tu 0 den N-1
    int swapped;
    do{
        swapped = 0;
        for (int i = 0; i < N; i++){
            if(A[i] > A[i+1]){
                int tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

int main(void){
    int n;
    int A[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    bubbleSort(A, n);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}