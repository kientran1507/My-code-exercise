#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int L, int R, int indexPivot){
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for(int i = L; i <= R; i++){
        if (A[i] < pivot){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(int A[], int L, int R){
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
        if(L < index)
            quickSort(A, L, index - 1);
        if(index < R)
            quickSort(A, index + 1, R);
    }
}


int main(void){
    int n;
    int A[100006];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
