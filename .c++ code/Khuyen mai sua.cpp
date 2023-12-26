#include <bits/stdc++.h>

#define N 20

using namespace std;

int n, m, year;
vector<int> arr;
int visited[N];
int c[N];
int result = 0;
int sum = 0;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        arr.push_back(m);
    }
    cin >> year;
    sort(arr.begin(), arr.end());
}

int check(int v, int k){
    if (visited[v])
        return 0;
    if (k == 1)
        return 1;
    else
        return arr[v] > c[k - 1];
}

void solution(int v){
    result += 1;
}

void Try(int k){
    for (int v = 0; v < n; v++){
        if (check(v, k)){
            c[k] = arr[v];
            sum += arr[v];
            visited[v] = 1;
            if (sum >= year && sum%5==0)
                solution(v);
            else
                Try(k + 1);
            sum -= arr[v];
            visited[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    Try(1);
    cout << result;
    return 0;
}
