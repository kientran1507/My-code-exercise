#include <bits/stdc++.h>

using namespace std;

//Function to check if the phone number is in correct format
bool isCorrect(const string &phoneNumber){
    return phoneNumber.length()==10;
}

//Function to calculate time difference between from_time and end_time
int timeDiff(const string &from_time, const string &end_time) {
    int from_h, from_m, from_s;
    int end_h, end_m, end_s;

    sscanf(from_time.c_str(), "%d:%d:%d", &from_h, &from_m, &from_s);
    sscanf(end_time.c_str(), "%d:%d:%d", &end_h, &end_m, &end_s);

    int from_seconds_total = from_h * 3600 + from_m * 60 + from_s;
    int end_seconds_total = end_h * 3600 + end_m * 60 + end_s;

    return end_seconds_total - from_seconds_total;
}

//Main function
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_map<string, int> callCounts;      
    unordered_map<string, int> callDurations;
    int totalCalls = 0;
    int faultNum = 0;
    while (true) {
        string key;
        getline(cin, key);
        if (key == "#"){
            break;
        }
        stringstream ss(key);
        string cmd, from_number, to_number, date, from_time, end_time;
        ss >> cmd >> from_number >> to_number >> date >> from_time >> end_time;
        if (cmd == "call"){
            if (!isCorrect(from_number) || !isCorrect(to_number)){
                faultNum++;
            }
            totalCalls++;
            callCounts[from_number]++;
            int callDuration = timeDiff(from_time, end_time);
            callDurations[from_number] += callDuration;
        }
    }


    while (true) {
        string query;
        getline(cin, query);
        if (query == "#") {
            break;
        }

        stringstream ss(query);
        string cmd;
        ss >> cmd;

        if (cmd == "?check_phone_number") {
            if (faultNum>0){
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else if (cmd == "?number_calls_from") {
            string phone_number;
            ss >> phone_number;
            cout << callCounts[phone_number] << "\n";
        } else if (cmd == "?number_total_calls") {
            cout << totalCalls << "\n";
        } else if (cmd == "?count_time_calls_from") {
            string phone_number;
            ss >> phone_number;
            cout << callDurations[phone_number] << "\n";
        }
    }
    return 0;
}