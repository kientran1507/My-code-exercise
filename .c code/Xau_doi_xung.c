#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return true; // Xâu có ít hơn hoặc bằng 1 ký tự luôn là đối xứng.
    }

    // Nếu ký tự ở đầu và cuối không khớp, xâu không đối xứng.
    if (str[start] != str[end]) {
        return false;
    }

    // Kiểm tra phần xâu con giữa start và end.
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[] = "abcdcba";
    int len = strlen(str);

    if (isPalindrome(str, 0, len - 1)) {
        printf("Xau la doi xung.\n");
    } else {
        printf("Xau khong la doi xung.\n");
    }

    return 0;
}
