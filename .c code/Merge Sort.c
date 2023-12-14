#include <stdio.h>

void merge(int A[], int L, int M, int R){
    // Tron hai day da sap A[L..M] va A[M+1..R]
    int i = L;
    int j = M+1;
    int n = R - L + 1;
    int TA[n]; 
    for (int k = L; k <= R; k++){
        if(i > M){
            TA[k - L] = A[j];
            j++;
        } else if (j > R){
            TA[k - L] = A[i];
            i++;
        } else {
            if (A[i] < A[j]){
                TA[k - L] = A[i];
                i++;
            } else {
                TA[k - L] = A[j];
                j++;
            }
        }
    }
    for (int k = L; k <= R; k++) A[k] = TA[k - L];
}

void mergeSort(int A[], int L, int R){
    if (L < R){
        int M  = (L+R)/2;
        mergeSort(A, L, M);
        mergeSort(A, M+1, R);
        merge(A, L, M, R);
    }
}

int main(void){
    int n;
    int A[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
