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

// Hàm sắp xếp trộn dựa trên tên và sau đó theo ngày tháng năm sinh
void merge(HoSo arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các mảng tạm thời
    HoSo L[n1], R[n2];

    // Sao chép dữ liệu sang các mảng tạm thời L[] và R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Hợp nhất hai mảng đã sắp xếp lại arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        int compareResult = strcmp(L[i].ten, R[j].ten);

        // So sánh tên
        if (compareResult < 0 || (compareResult == 0 && L[i].namSinh <= R[j].namSinh && L[i].thangSinh <= R[j].thangSinh && L[i].ngaySinh <= R[j].ngaySinh)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép phần còn lại của L[] nếu có
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Sao chép phần còn lại của R[] nếu có
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Hàm sắp xếp trộn
void mergeSort(HoSo arr[], int left, int right) {
    if (left < right) {
        // Tìm điểm giữa
        int mid = left + (right - left) / 2;

        // Sắp xếp từng nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Hợp nhất các nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *file = fopen("ho_so.txt", "r");
    
    // Kiểm tra xem tệp có mở thành công không
    if (file == NULL) {
        printf("Khong the mo tep de doc.");
        return 1; // Kết thúc chương trình với mã lỗi
    }

    // Đếm số lượng hồ sơ trong file
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '#') {
            count++;
        }
    }

    // Di chuyển về đầu tệp
    rewind(file);

    // Đọc thông tin từ file vào mảng hồ sơ
    HoSo *arr = (HoSo *)malloc(count * sizeof(HoSo));
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s %s", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fscanf(file, "%d-%d-%d", &arr[i].namSinh, &arr[i].thangSinh, &arr[i].ngaySinh);
        // Đọc dòng cuối cùng
        fscanf(file, "#");
    }

    // Đóng tệp
    fclose(file);

    // Sắp xếp mảng hồ sơ
    mergeSort(arr, 0, count - 1);

    // Mở tệp để ghi thông tin đã sắp xếp
    file = fopen("ho_so_sapxep.txt", "w");

    // Kiểm tra xem tệp có mở thành công không
    if (file == NULL) {
        printf("Khong the mo tep de ghi.");
        return 1; // Kết thúc chương trình với mã lỗi
    }

    // Ghi thông tin đã sắp xếp vào tệp mới
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", arr[i].ho, arr[i].tenDem, arr[i].ten);
        fprintf(file, "%04d-%02d-%02d\n", arr[i].namSinh, arr[i].thangSinh, arr[i].ngaySinh);
        if (i < count - 1) {
            fprintf(file, "#\n"); // Dòng cuối cùng của mỗi hồ sơ (trừ hồ sơ cuối cùng)
        }
    }

    // Đóng tệp
    fclose(file);

    // Giải phóng bộ nhớ đã cấp phát cho mảng
    free(arr);

    return 0;
}
