#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to recursively find prime factors of a number
void findPrimeFactors(int n, vector<int>& factors, int divisor = 2) {
    if (n < 2) return;
    if (n % divisor == 0) {
        factors.push_back(divisor);
        findPrimeFactors(n / divisor, factors, divisor);
    } else {
        findPrimeFactors(n, factors, divisor + 1);
    }
}

// Function to check if a number is divisible by a prime factor
bool isDivisibleByPrimeFactor(int num, int prime) {
    return (num % prime == 0);
}

// Function to calculate the HCF from common prime factors
int calculateHCF(const vector<int>& factors1, const vector<int>& factors2) {
    vector<int> commonFactors;
    vector<int> tempFactors2 = factors2; // To handle duplicates
    for (int prime : factors1) {
        auto it = find(tempFactors2.begin(), tempFactors2.end(), prime);
        if (it != tempFactors2.end()) {
            commonFactors.push_back(prime);
            tempFactors2.erase(it); // Remove to avoid reuse
        }
    }
    int hcf = 1;
    for (int factor : commonFactors) {
        hcf *= factor;
    }
    return hcf;
}

// Main function
int main() {
    int num1, num2;
    cout << "Enter two natural numbers: ";
    cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Both numbers must be natural numbers (greater than 0)." << endl;
        return 1;
    }

    vector<int> factors1, factors2;

    // Find prime factors of both numbers
    findPrimeFactors(num1, factors1);
    findPrimeFactors(num2, factors2);

    // Calculate HCF using common prime factors
    int hcf = calculateHCF(factors1, factors2);

    // Display the result
    cout << "The HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;

    return 0;
}

