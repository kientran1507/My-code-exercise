#include <iostream>
#include <string>
using namespace std;

int* GetBigInteger(string str)
{
    int x = str.size();
    int* arr = new int[str.size()];

    for (int a = 0; a < x; a++) {
        arr[a] = str[a] - '0';
    }

    return arr;
}

int main()
{
    cout << "Enter a 1000-digit number (one line at a time):" << endl;

    string str;
    string input_line;
    for (int i = 0; i < 20; i++) {
        cin >> input_line;  // Read one line at a time
        str += input_line;  // Concatenate the lines
    }

    int* arr = GetBigInteger(str);

    long long int max = 0;

    for (int i = 0; i <= str.size() - 13; i++) {
        long long int product = 1;
        for (int j = 0; j < 13; j++) {
            product *= arr[i + j];
        }
        if (product > max) {
            max = product;
        }
    }

    cout << "Maximum product of 13 consecutive digits: " << max << endl;

    delete[] arr;

    return 0;
}
