#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    double cpu_time_used;
    int n;
    int A[100006];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    start = clock();
    bubbleSort(A, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}