#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> MyStack;
    string cmd;

    while (cin >> cmd){
        if (cmd == "PUSH"){
            int value;
            cin >> value;
            MyStack.push(value);
        } else if (cmd == "POP"){
            if (!MyStack.empty()){
                cout << MyStack.top() << endl;
                MyStack.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
    
    return 0;
}