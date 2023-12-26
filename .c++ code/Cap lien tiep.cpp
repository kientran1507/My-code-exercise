#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007; // mod = 10^9 + 7
int n;
int a;
vector<int> arr;
vector<int> path;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
}

void findPairs(const vector<int>& arr, int start, vector<int>& path, int& count) {
    if (path.size() == 2) {
        int diff = path[1] - path[0];
        if (diff == 1) {
            count++;
            //cout << "(" << path[0] << ", " << path[1] << ")" << endl;
        }
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        // Ensure a[i] < a[j]
        if (!path.empty() && arr[i] <= path.back()) continue;

        path.push_back(arr[i]);
        findPairs(arr, i + 1, path, count);
        path.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int count = 0;

    findPairs(arr, 0, path, count);

    cout << count % MOD << endl;

    return 0;
}
