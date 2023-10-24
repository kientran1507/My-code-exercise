#include <stdio.h>
#include <string.h>

// Function to add two big numbers
void addBigNumbers(char num1[], char num2[], char result[], int maxSize) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;

    if (maxLen >= maxSize) {
        printf("Result size exceeds maximum size.\n");
        return;
    }

    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
    }

    if (carry > 0) {
        result[k] = carry + '0';
        k++;
    }

    result[k] = '\0';

    // Reverse the result
    for (i = 0, j = k - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

int main() {
    char num1[100]; // Specify the size of the array
    char num2[100]; // Specify the size of the array
    char result[100]; // Adjust the size as needed

    scanf("%s", num1);
    scanf("%s", num2);
    
    addBigNumbers(num1, num2, result, sizeof(result));

    printf("%s\n", result);

    return 0;
}
