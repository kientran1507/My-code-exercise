#include <stdio.h>
#include <math.h>

void move1(int n, int k, char from, char temp, char to) {
    if (n == 0) {
        printf("\n");
        return;
    }
    move1(n - 1, k, from, to, temp);
    printf("Move disk %d from %c to %c", n + k, from, to);
    move1(n - 1, k, temp, from, to);
}
void move2(int n, char from, char temp, char to, char temp2) {
    int k = n + 1 - round(sqrt(2 * n + 1));
    if (k == 0) {
        printf("Move disk 1 from %c to %c", from, to);
        return;
    }
    move2(k, from, to, temp, temp2);
    move1(n-k, k, from, temp2, to);
    move2(k, temp, from, to, temp2);
    }

int main() {
    int n = 6; // Change n to the desired number of disks
    move2(n, 'A', 'B', 'C', 'D');
    return 0;
}
