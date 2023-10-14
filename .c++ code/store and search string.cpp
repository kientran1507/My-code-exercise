#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    unordered_set<string> database;
    string key;

    // Read the keys into the database
    while (true) {
        getline(cin, key);
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    // Process actions
    while (true) {
        string cmd, k;
        cin >> cmd >> k;
        if (cmd == "***") {
            break;
        }
        if (cmd == "find") {
            if (database.find(k) != database.end()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (cmd == "insert") {
            if (database.find(k) != database.end()) {
                cout << "0\n";
            } else {
                database.insert(k);
                cout << "1\n";
            }
        }
    }

    return 0;
}
