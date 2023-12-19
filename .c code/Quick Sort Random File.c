#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc chứa thông tin về tên và ngày tháng năm sinh
typedef struct {
    char ho[20];
    char tenDem[20];
    char ten[20];
    int namSinh;
    int thangSinh;
    int ngaySinh;
} HoSo;

// Hàm swap đổi chỗ 2 giá trị
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

int partition(HoSo A[], int L, int R) {
    HoSo pivot = A[R];
    int storeIndex = L;
    for (int i = L; i < R; i++) {
        if (compare(A[i], pivot) < 0) {
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(HoSo arr[], int L, int R) {
    if (L < R) {
        int index = partition(arr, L, R);
        quickSort(arr, L, index - 1);
        quickSort(arr, index + 1, R);
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
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s %s", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fscanf(file, "%d-%d-%d", &arr[i].namSinh, &arr[i].thangSinh, &arr[i].ngaySinh);
    }
    fclose(file);

    quickSort(arr, 0, count - 1);

    file = fopen("ho_so_sapxep_quicksort.txt", "w");
    if (file == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fprintf(file, "%04d-%02d-%02d\n", arr[i].namSinh, arr[i].thangSinh, arr[i].ngaySinh);
    }
    fprintf(file, "#\n");
    fclose(file);

    free(arr);
    return 0;
}
