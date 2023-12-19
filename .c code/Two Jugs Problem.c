#include <stdio.h>

// Swap two integer values
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Compute the greatest common divisor using Euclidean algorithm
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Return the minimum of two integers
int min(int a, int b){
    return (a <= b) ? a : b;
}

// Simulate pouring water from one jug to another until reaching the target amount
int pour(int fromJug, int toJug, int d){
    int from = fromJug;
    int to = 0;
    int step = 1;

    while (from != d && to != d){
        int temp = min(from, toJug - to);
        to += temp;
        from -= temp;
        step++;
        
        // If the desired amount is reached in either jug, exit the loop
        if (from == d || to == d) break;

        // If the 'from' jug becomes empty, refill it
        if (from == 0){
            from = fromJug;
            step++;
        }

        // If the 'to' jug becomes full, empty it
        if (to == toJug){
            to = 0;
            step++;
        }
    }

    return step;
}

// Calculate the minimum number of steps required to measure 'd' liters of water
int minStep(int m, int n, int d){
    // Ensure that m is smaller than or equal to n
    if (m > n) swap(&m, &n);
    
    // If the target amount is greater than the larger jug's capacity, it's impossible
    if (d > n) return -1;
    
    // If 'd' is not a multiple of the greatest common divisor of m and n, it's impossible
    if ((d % gcd(n, m)) != 0) return -1;
    
    // Return the minimum of two pouring simulations
    return min(pour(n, m, d), pour(m, n, d));
}

int main(){
    int m, n, d;

    // Input the capacities of the two jugs and the target amount
    scanf("%d %d %d", &m, &n, &d);
    
    // Calculate and print the minimum number of steps
    printf("%d", minStep(m, n, d));
    
    return 0;
}
