#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007; // 10^9 + 7

// Function to calculate (x^y) % MOD
unsigned long long power(unsigned long long x, unsigned long long y) {
    unsigned long long result = 1;
    x = x % MOD;

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            result = (result * x) % MOD;

        // y must be even now
        y = y / 2;
        x = (x * x) % MOD;
    }

    return result;
}

int main() {
    unsigned long long a, b;
    cin >> a >> b;

    // Calculate a^b % MOD
    unsigned long long result = power(a, b);

    cout << result << endl;

    return 0;
}
