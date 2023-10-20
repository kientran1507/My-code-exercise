#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int nr){
    int rev = 0; // reversed number
    int x = nr; // default value

    while (x > 0){
        rev = 10 * rev + x % 10;
        x /= 10;
    }
    return rev == nr; // return true if the number is palindrome
}

int main(void){
    int max = -1;
    for (int i = 999; i >= 100; i--){
        if (max >= i*999) break;
        for (int j = 999; j >= 100; j--){
            int p = i * j;
            if (max < p && isPalindrome(p)){
                max = p;
            }
        }
    }
    printf("%d", max);
}
