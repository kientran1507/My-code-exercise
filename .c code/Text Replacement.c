#include <stdio.h>
#include <string.h>

// Hàm để thay thế xâu P1 bằng xâu P2 trong xâu T
void replaceString(char* T, const char* P1, const char* P2) {
    char* position = T;
    int lenP1 = strlen(P1);
    int lenP2 = strlen(P2);

    while ((position = strstr(position, P1)) != NULL) {
        memmove(position + lenP2, position + lenP1, strlen(position + lenP1) + 1);
        memcpy(position, P2, lenP2);
        position += lenP2;
    }
}

int main() {
    char P1[1001];
    char P2[1001];
    char T[10001];

    // Đọc xâu P1, xâu P2 và văn bản T từ dữ liệu đầu vào
    fgets(P1, 1001, stdin);
    fgets(P2, 1001, stdin);
    fgets(T, 10001, stdin);

    // Loại bỏ ký tự newline '\n' nếu có
    size_t lenP1 = strlen(P1);
    if (lenP1 > 0 && P1[lenP1 - 1] == '\n') {
        P1[lenP1 - 1] = '\0';
    }

    size_t lenP2 = strlen(P2);
    if (lenP2 > 0 && P2[lenP2 - 1] == '\n') {
        P2[lenP2 - 1] = '\0';
    }

    size_t lenT = strlen(T);
    if (lenT > 0 && T[lenT - 1] == '\n') {
        T[lenT - 1] = '\0';
    }

    // Thực hiện thay thế
    replaceString(T, P1, P2);

    // In ra kết quả
    printf("%s\n", T);

    return 0;
}
