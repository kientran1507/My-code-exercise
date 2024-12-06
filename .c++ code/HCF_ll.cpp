#include <iostream>
#include <cmath>
using namespace std;

// Node structure to store prime factor, its frequency, and the next pointer
struct Node {
    int value;         // Prime factor
    int frequency;     // Frequency of the prime factor
    Node* next;        // Pointer to the next node

    Node(int val, int freq) : value(val), frequency(freq), next(nullptr) {}
};

// Function to add a prime factor to the linked list or update its frequency
void addFactor(Node*& head, int prime) {
    Node* current = head;

    // Check if the prime factor already exists in the list
    while (current != nullptr) {
        if (current->value == prime) {
            current->frequency++; // Increment frequency if already exists
            return;
        }
        current = current->next;
    }

    // If prime factor is not in the list, add a new node
    Node* newNode = new Node(prime, 1);
    newNode->next = head;
    head = newNode;
}

// Function to recursively find prime factors and add to the linked list
void findPrimeFactors(int n, Node*& head, int divisor = 2) {
    if (n < 2) return;
    if (n % divisor == 0) {
        addFactor(head, divisor);
        findPrimeFactors(n / divisor, head, divisor);
    } else {
        findPrimeFactors(n, head, divisor + 1);
    }
}

// Function to find common prime factors and calculate HCF
int calculateHCF(Node* head1, Node* head2) {
    int hcf = 1;

    while (head1 != nullptr) {
        Node* temp = head2;
        while (temp != nullptr) {
            if (head1->value == temp->value) {
                // Multiply the HCF with the prime factor raised to the minimum frequency
                hcf *= pow(head1->value, min(head1->frequency, temp->frequency));
                break;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return hcf;
}

// Function to free memory allocated for the linked list
void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
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

    Node* factors1 = nullptr;
    Node* factors2 = nullptr;

    // Find prime factors for both numbers and store in linked lists
    findPrimeFactors(num1, factors1);
    findPrimeFactors(num2, factors2);

    // Calculate HCF from the linked lists
    int hcf = calculateHCF(factors1, factors2);

    // Display the result
    cout << "The HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;

    // Free allocated memory
    freeList(factors1);
    freeList(factors2);

    return 0;
}
