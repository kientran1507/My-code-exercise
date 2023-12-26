#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;
const int INF = 1e9;
int R, C;
int cost[N][N];
int min(int x, int y, int z);

int minCost(int cost[N][N], int m, int n)
{
	int i, j;

	int tc[R][C];

	tc[0][0] = cost[0][0];

	for (i = 1; i <= m; i++){
		tc[i][0] = tc[i - 1][0] + cost[i][0];
    }

	for (j = 1; j <= n; j++){
		tc[0][j] = tc[0][j - 1] + cost[0][j];
    }

	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];
        }
    }

	return tc[m][n];
}

int min(int x, int y, int z){
	return min(x, min(y, z));
}

int main()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
			cin >> cost[i][j];
			if (cost[i][j] == 0) cost[i][j] = INF;
		}
	}
	cout << minCost(cost, R-1, C-1);
	return 0;
}

