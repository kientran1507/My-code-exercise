#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int minX = 101, minY = 101;  // Khởi tạo giá trị tối đa
    int maxX = 0, maxY = 0;      // Khởi tạo giá trị tối thiểu

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Tìm giá trị tối đa và tối thiểu của x và y
        if (x1 < minX) minX = x1;
        if (x2 < minX) minX = x2;
        if (y1 < minY) minY = y1;
        if (y2 < minY) minY = y2;

        if (x1 > maxX) maxX = x1;
        if (x2 > maxX) maxX = x2;
        if (y1 > maxY) maxY = y1;
        if (y2 > maxY) maxY = y2;
    }

    int area = (maxX - minX) * (maxY - minY);
    printf("%d\n", area);

    return 0;
}
