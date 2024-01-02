#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100001

int a[N];
int n, Q;

int cand[N];
int sz;

void initSet(int _sz){
    for(int i = 0; i < _sz; i++) cand[i] = i+1;
    for(int k = 0; k < _sz; k++){
        int i = rand() % _sz;
        int j = rand() % _sz;
        int tmp = cand[i];
        cand[i] = cand[j];
        cand[j] = tmp;
    }
    sz = _sz;
}

int selectAndRemove(){
    int i = rand() % sz;
    int x = cand[i];
    cand[i] = cand[sz-1];
    sz--;
    return x;
}

void genData(char* filename, int n, int Q){
    srand(time(NULL));
    FILE* f = fopen(filename, "w");
    fprintf(f, "%d %d\n", n, Q);
    initSet(n);
    for(int i = 0; i < n; i++){
        int x = selectAndRemove();
        fprintf(f, "%d ", x);
    }
    fclose(f);
}

void input(char* filename){
    FILE* f = fopen(filename, "r");
    fscanf(f, " %d %d", &n, &Q);
    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }
    fclose(f);
}

void bruteForceSolve(){
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] + a[j] == Q){
                cnt++;
            }
        }
    }
    printf("result = %d\n", cnt);
}

void swap(int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int i, int n){
    int L = 2*i + 1;
    int R = 2*i + 2;
    int max = i;
    if(L < n && a[L] > a[max]) max = L;
    if(R < n && a[R] > a[max]) max = R;
    if(max != i){
        swap(i, max);
        heapify(max, n);
    }
}

void buildHeap(){
    for(int i = n/2 - 1; i >= 0; i--) heapify(i, n);
}

void heapSort(){
    buildHeap();
    for(int i = n-1; i > 0; i--){
        swap(0, i);
        heapify(0, i);
    }
}

int binarySearch(int L, int R, int Y){
    if(L <= R){
        int m = L + (R - L) / 2;
        if(a[m] == Y) return 1;
        if(a[m] < Y) return binarySearch(m+1, R, Y);
        return binarySearch(L, m-1, Y);
    }
    return 0;
}

void binarySearchSolve(){
    heapSort();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int ok = binarySearch(i+1, n-1, Q-a[i]);
        cnt += ok;
    }
    printf("result = %d\n", cnt);
}

int main(){
    genData("arr-100000.txt" , 100000, 100000);
    input("arr-100000.txt");
    bruteForceSolve();
    binarySearchSolve();
    return 0;
}
