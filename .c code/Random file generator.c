#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cấu trúc chứa thông tin về tên
typedef struct {
    char ho[20];
    char tenDem[20];
    char ten[20];
} HoSo;

// Hàm chọn ngẫu nhiên một phần của tên từ danh sách
char* getRandomHo() {
    char *ho[] = {"Nguyen", "Tran", "Le", "Pham", "Vo", "Bui", "Dang", "Do", "Vu", "Dinh"};
    int numHo = sizeof(ho) / sizeof(ho[0]);
    int randomIndex = rand() % numHo;
    return ho[randomIndex];
}

char* getRandomTenDem() {
    char *tenDem[] = {"Van", "Thi", "An", "Hong", "Minh", "Manh", "Duy", "Hieu", "Cong", "Thanh"};
    int numTenDem = sizeof(tenDem) / sizeof(tenDem[0]);
    int randomIndex = rand() % numTenDem;
    return tenDem[randomIndex];
}

char* getRandomTen() {
    char *ten[] = {"Hoa", "Mai", "Lan", "Anh", "Tuan", "Nam", "Quynh", "Trang", "Huong", "Duc"};
    int numTen = sizeof(ten) / sizeof(ten[0]);
    int randomIndex = rand() % numTen;
    return ten[randomIndex];
}

// Hàm sinh ngày tháng năm sinh ngẫu nhiên
void generateRandomDate(int *year, int *month, int *day) {
    *year = rand() % (2005 - 1980 + 1) + 1980; // Năm sinh từ 1980 đến 2005
    *month = rand() % 12 + 1; // Tháng từ 1 đến 12
    *day = rand() % 31 + 1;   // Ngày từ 1 đến 31
}

int main() {
    int n = 10; // Số lượng hồ sơ cần sinh

    // Mở tệp để ghi thông tin
    FILE *file = fopen("ho_so.txt", "w");

    // Kiểm tra xem tệp có mở thành công không
    if (file == NULL) {
        printf("Khong the mo tep de ghi.");
        return 1; // Kết thúc chương trình với mã lỗi
    }

    // Sinh ngẫu nhiên n hồ sơ
    for (int i = 0; i < n; ++i) {
        fprintf(file, "%s %s %s\n", getRandomHo(), getRandomTenDem(), getRandomTen());

        int year, month, day;
        generateRandomDate(&year, &month, &day);
        fprintf(file, "%04d-%02d-%02d\n", year, month, day);
    }
    fprintf(file, "#\n"); // Dòng cuối cùng của hồ sơ
    
    // Đóng tệp
    fclose(file);

    return 0;
}
