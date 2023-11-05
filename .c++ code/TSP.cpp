#include <bits/stdc++.h>
#define N 2000000
using namespace std;
int M[32][N];
int n;
int d[32][32];

unsigned int removeItem(unsigned int S, int i){
	// remove the item i from the set S
	return S ^ (1 << i);
}
unsigned int addItem(unsigned int S, int i){
	return S | (1 << i);
}
bool contains(unsigned int S, int i){
	// return true if j belongs to the set S
	if(((S >> i) & 1) > 0)
		return true;
	return false;
}
void printBitString(unsigned int S){
	char s[32];
	int n = 31;
	s[n]= '\0';
	while(S > 0){
		int b = S%2;
		n--;
		if(b == 0) s[n] = '0';
		else s[n] = '1';
		S = S/2;
	}
	while(n > 0){
		n--;
		s[n] = '0';
	}
	cout << s << endl;
}
void printSet(unsigned int S){
	cout << "{";
	for(int i = 0; i <= 31; i++){
		if(contains(S,i)) cout << i << " ";
	}
	cout << "}" << endl;
}

int TSP(int i, unsigned int S){
	if(S == 0){
		M[i][S] = d[i][1];
	}else if(M[i][S] == -1){// BTC chua duoc solved
		M[i][S] = 100000000;
		for(int j = 1; j <= n; j++){
			if(contains(S,j)){
				int tmp = TSP(j,removeItem(S,j));
				if(M[i][S] > d[i][j] + tmp){
					M[i][S] = d[i][j] + tmp;
				}
			}
		}
	}
	return M[i][S];
}
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d",&d[i][j]);
	unsigned int S = 0;
	for(int i = 2; i <= n; i++)
		S = addItem(S,i);
	for(int i = 0; i < 32; i++)
		for(int j = 0; j < N; j++)
			M[i][j] = -1;

	int res = TSP(1,S);
	cout << res;
	/*
	unsigned int S = 0;
	for(int i = 1; i <= 31; i++)
		S = addItem(S,i);
	printBitString(S);
	printSet(S);


	S = removeItem(S,3);
	printBitString(S);
	printSet(S);
	*/
	return 0;
}
