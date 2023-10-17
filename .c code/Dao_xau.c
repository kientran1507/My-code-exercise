#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

int main() {
    char inputString[100];
    
    printf("Enter a string: ");
    scanf("%s", inputString);

    int len = strlen(inputString);
    reverseString(inputString, 0, len - 1);

    printf("Reversed string: %s\n", inputString);

    return 0;
}
