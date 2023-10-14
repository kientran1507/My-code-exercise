#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> MyQueue;
    string cmd;

    while (cin >> cmd){
        if (cmd == "PUSH"){
            int value;
            cin >> value;
            MyQueue.push(value);
        } else if (cmd == "POP"){
            if (!MyQueue.empty()){
                cout << MyQueue.front() << endl;
                MyQueue.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
    
    return 0;
}