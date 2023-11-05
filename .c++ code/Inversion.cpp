#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // Set the maximum size of the array

int a[MAXN], temp[MAXN];
int n;
const int MOD = 1000000007; // Define the MOD value

int merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid - i + 1)) % MOD;
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i];
    }

    return inv_count;
}

int mergeSort(int left, int right) {
    int inv_count = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;

        inv_count = (inv_count + mergeSort(left, mid)) % MOD;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
        inv_count = (inv_count + merge(left, mid, right)) % MOD;
    }
    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int inversions = mergeSort(1, n);
    cout << inversions << endl;

    return 0;
}
