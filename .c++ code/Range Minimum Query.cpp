#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cin >> m;

    int Q = 0;
    for (int i = 0; i < m; ++i) {
        int query_start, query_end;
        cin >> query_start >> query_end;

        int min_value = numeric_limits<int>::max();
        for (int j = query_start; j <= query_end; ++j) {
            min_value = min(min_value, a[j]);
        }

        Q += min_value;
    }

    cout << Q << endl;

    return 0;
}
