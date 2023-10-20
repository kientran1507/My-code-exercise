#include <stdio.h>

int sumSquare = 0;
int squareSum = 0;

int main(void){
    for (int i = 1; i <= 100; i++){
        sumSquare += i*i;
        squareSum += i;
    }
    squareSum *= squareSum;
    int diff = squareSum - sumSquare;
    printf("%d", diff);
}