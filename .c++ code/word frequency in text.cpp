#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> wordCount;
    string word;

    // Read and tokenize the input text
    while (cin >> word) {
        // Remove non-alphanumeric characters and convert to lowercase
        string cleanedWord;
        for (char c : word) {
            if (isalnum(c)) {
                cleanedWord += tolower(c);
            }
        }

        // Increment the word count
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }

    // Output the words and their counts in lexicographic order
    for (const auto& entry : wordCount) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
