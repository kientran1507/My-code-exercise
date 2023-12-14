#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    double cpu_time_used;
    int n;
    int A[100006];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    start = clock();
    selectionSort(A, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}