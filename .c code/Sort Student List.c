#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int stt;
    char ho[20];
    char tenDem[20];
    char ten[20];
    char mssv[8];
    float diemThi;
} SinhVien;

void swap(SinhVien* a, SinhVien* b) {
    SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

int partition(SinhVien* arr, int low, int high, char ch) {
    SinhVien pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        switch (ch) {
            case 'n':
                if (strcmp(arr[j].ten, pivot.ten) < 0) {
                    i++;
                    swap(&arr[i], &arr[j]);
                } else if (strcmp(arr[j].ten, pivot.ten) == 0 && arr[j].stt < pivot.stt) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
                break;
            case 'g':
                if (arr[j].diemThi > pivot.diemThi) {
                    i++;
                    swap(&arr[i], &arr[j]);
                } else if (arr[j].diemThi == pivot.diemThi && arr[j].stt < pivot.stt) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
                break;
            case 'c':
                if (strcmp(arr[j].mssv, pivot.mssv) < 0) {
                    i++;
                    swap(&arr[i], &arr[j]);
                } else if (strcmp(arr[j].mssv, pivot.mssv) == 0 && arr[j].stt < pivot.stt) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
                break;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(SinhVien* arr, int low, int high, char ch) {
    if (low < high) {
        int pi = partition(arr, low, high, ch);

        quicksort(arr, low, pi - 1, ch);
        quicksort(arr, pi + 1, high, ch);
    }
}

void printSinhVienList(SinhVien* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d*%s %s %s*%s*%0.2f\n", arr[i].stt, arr[i].ho, arr[i].tenDem, arr[i].ten, arr[i].mssv, arr[i].diemThi);
    }
}

int main() {
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    SinhVien* danhSach = (SinhVien*)malloc(n * sizeof(SinhVien));

    for (int i = 0; i < n; i++) {
        scanf("%d*%20[^ ] %20[^ ] %20[^*]*%8[^*]*%f%*c", &danhSach[i].stt, danhSach[i].ho, danhSach[i].tenDem, danhSach[i].ten, danhSach[i].mssv, &danhSach[i].diemThi);
    }

    quicksort(danhSach, 0, n - 1, ch);

    printSinhVienList(danhSach, n);

    free(danhSach);

    return 0;
}
