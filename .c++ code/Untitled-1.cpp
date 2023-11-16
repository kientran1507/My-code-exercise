#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007; // 10^9 + 7

// Function to calculate (x^y) % MOD using dynamic programming
unsigned long long int power(unsigned long long int x, unsigned long long int y) {
    if (y == 0) {
        return 1;
    }

    unsigned long long int half_pow = power(x, y / 2);
    unsigned long long int result = (half_pow * half_pow) % MOD;

    if (y % 2 == 1) {
        result = (result * x) % MOD;
    }

    return result;
}

int main() {
    unsigned long long int a, b;
    cin >> a >> b;

    // Calculate a^b % MOD
    unsigned long long int result = power(a, b);

    cout << result << endl;

    return 0;
}
