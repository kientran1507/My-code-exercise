#include <stdio.h>
#include <string.h>

void reverseWords(char *words[], int wordCount) {
    // Đảo ngược thứ tự các từ trong mảng
    for (int i = 0, j = wordCount - 1; i < j; i++, j--) {
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Sử dụng: <từ 1> <từ 2> ... <từ n>\n");
        return 1;
    }

    // Truyền từng từ như một đối số riêng biệt vào mảng words[]
    char *words[argc - 1];
    for (int i = 1; i < argc; i++) {
        words[i - 1] = argv[i];
    }

    printf("Cau ban dau: ");
    for (int i = 0; i < argc - 1; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    reverseWords(words, argc - 1);

    printf("Cau dao nguoc: ");
    for (int i = 0; i < argc - 1; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
