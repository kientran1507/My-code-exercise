#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    double cpu_time_used;
    int n;
    int A[100006];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    start = clock();
    insertionSort(A, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}