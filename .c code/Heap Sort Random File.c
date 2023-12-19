#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ho[20];
    char tenDem[20];
    char ten[20];
    int namSinh;
    int thangSinh;
    int ngaySinh;
} HoSo;

void swap(HoSo *a, HoSo *b) {
    HoSo temp = *a;
    *a = *b;
    *b = temp;
}

int compare(HoSo a, HoSo b) {
    int cmp = strcmp(a.ten, b.ten);
    if (cmp != 0) return cmp;

    cmp = strcmp(a.tenDem, b.tenDem);
    if (cmp != 0) return cmp;

    cmp = strcmp(a.ho, b.ho);
    if (cmp != 0) return cmp;

    if (a.namSinh != b.namSinh) return a.namSinh - b.namSinh;
    if (a.thangSinh != b.thangSinh) return a.thangSinh - b.thangSinh;
    return a.ngaySinh - b.ngaySinh;
}

void heapify(HoSo A[], int i, int N){
    int L = 2*i;
    int R = 2*i + 1;
    int max = i;
    if (L <= N && compare(A[L], A[i]) > 0) max = L;
    if (R <= N && compare(A[R], A[max]) > 0) max = R;
    if (max != i){
        swap(&A[i], &A[max]);
        heapify(A, max, N);
    }
}

void buildHeap(HoSo A[], int N){
    for(int i = N/2; i >= 1; i--){
        heapify(A, i, N);
    }
}

void heapSort(HoSo A[], int N){
    buildHeap(A, N);
    for (int i = N; i > 1; i--){
        swap(&A[1], &A[i]);
        heapify(A, 1, i-1);
    }
}

int main() {
    FILE *file = fopen("ho_so.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep de doc.\n");
        return 1;
    }

    int count = 10;
    rewind(file);

    HoSo *arr = (HoSo *)malloc(count * sizeof(HoSo));
    for (int i = 1; i <= count; i++) { // Start index from 1 for heapify and heapsort
        fscanf(file, "%s %s %s", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fscanf(file, "%d-%d-%d", &arr[i].namSinh, &arr[i].thangSinh, &arr[i].ngaySinh);
    }
    fclose(file);

    heapSort(arr, count - 1);

    file = fopen("ho_so_sapxep_heapsort.txt", "w");
    if (file == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return 1;
    }

    for (int i = 1; i <= count; i++) {
        fprintf(file, "%s %s %s\n", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fprintf(file, "%04d-%02d-%02d\n", arr[i].namSinh, arr[i].thangSinh, arr[i].ngaySinh);
    }
    fprintf(file, "#\n");
    fclose(file);

    free(arr);
    return 0;
}
