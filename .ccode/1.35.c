#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Định nghĩa cấu trúc cho hình tròn
typedef struct {
    float x; // Tọa độ x của tâm
    float y; // Tọa độ y của tâm
    float radius; // Bán kính
} Circle;

// Hàm kiểm tra xem hai hình tròn có giao nhau hay không
int circlesIntersect(Circle circle1, Circle circle2) {
    float distance = sqrt(pow(circle2.x - circle1.x, 2) + pow(circle2.y - circle1.y, 2));
    return distance <= (circle1.radius + circle2.radius);
}

// Hàm để tạo thông tin ngẫu nhiên cho một hình tròn
void generateRandomCircleInfo(Circle *circle) {
    circle->x = (float)(rand() % 100); // Tọa độ x từ 0 đến 99
    circle->y = (float)(rand() % 100); // Tọa độ y từ 0 đến 99
    circle->radius = (float)(rand() % 10) + 1; // Bán kính từ 1 đến 10
}

int main() {
    int n; // Số lượng hình tròn
    printf("Nhập số lượng hình tròn: ");
    scanf("%d", &n);

    // Tạo mảng động lưu trữ các hình tròn
    Circle *circles = (Circle *)malloc(n * sizeof(Circle));

    int choice;
    printf("Lựa chọn:\n");
    printf("1. Nhập thủ công thông tin cho mỗi hình tròn\n");
    printf("2. Tự động sinh thông tin ngẫu nhiên cho mỗi hình tròn\n");
    printf("Chọn: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Nhập thông tin cho mỗi hình tròn
        for (int i = 0; i < n; i++) {
            printf("Hình tròn %d:\n", i + 1);
            printf("Nhập tọa độ x của tâm: ");
            scanf("%f", &circles[i].x);
            printf("Nhập tọa độ y của tâm: ");
            scanf("%f", &circles[i].y);
            printf("Nhập bán kính: ");
            scanf("%f", &circles[i].radius);
        }
    } else if (choice == 2) {
        // Tự động sinh thông tin ngẫu nhiên cho mỗi hình tròn
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            generateRandomCircleInfo(&circles[i]);
        }
    } else {
        printf("Lựa chọn không hợp lệ.\n");
        free(circles);
        return 1;
    }

    // Kiểm tra và hiển thị thông tin về giao nhau của các hình tròn
    printf("\nThông tin về các hình tròn:\n");
    for (int i = 0; i < n; i++) {
        printf("Hình tròn %d: Tâm (%.2f, %.2f), Bán kính %.2f\n", i + 1, circles[i].x, circles[i].y, circles[i].radius);

        int maxIntersections = 0;
        int furthestCircleIndex = -1;

        printf("Giao với các hình tròn khác:\n");
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (circlesIntersect(circles[i], circles[j])) {
                    printf("- Hình tròn %d\n", j + 1);

                    // Đếm số hình tròn mà hình tròn hiện tại giao với
                    int intersections = 1; // Bắt đầu từ 1 vì hình tròn luôn giao với chính nó
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j && circlesIntersect(circles[i], circles[k])) {
                            intersections++;
                        }
                    }

                    // Cập nhật thông tin về hình tròn giao với nhiều hình tròn khác nhất
                    if (intersections > maxIntersections) {
                        maxIntersections = intersections;
                        furthestCircleIndex = j;
                    }
                }
            }
        }

        if (furthestCircleIndex != -1) {
            printf("Hình tròn giao với nhiều hình tròn khác nhất là hình tròn %d với %d lần giao.\n", furthestCircleIndex + 1, maxIntersections);
        } else {
            printf("Không giao với hình tròn nào khác.\n");
        }

        printf("\n");
    }

    // Giải phóng bộ nhớ mảng động
    free(circles);

    return 0;
}
