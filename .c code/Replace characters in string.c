#include <stdio.h>
#include <string.h>

// Function to replace every occurrence of char 'from' with char 'to' in a string
void replaceChars(char* str, char from, char to) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == from) {
            str[i] = to;
        }
    }
}

int main() {
    char inputString[100];
    char fromChar, toChar;

    // Read the input string from the user
    scanf("%s", inputString);

    // Read the characters to be replaced
    scanf(" %c", &fromChar); // Note the space before %c to consume any previous newline character

    scanf(" %c", &toChar);

    // Call the function to replace characters
    replaceChars(inputString, fromChar, toChar);

    // Print the modified string
    printf("%s\n", inputString);

    return 0;
}
