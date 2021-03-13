//p53~ ナップサック問題
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

//入力
int n = 4, W = 5, w[MAX_N] = {2, 1, 3, 2}, v[MAX_N] = {3, 2, 4, 2};

//i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j){
    int res;
    if(i == n){
        //もう品物は残っていない
        res = 0;
    } else if(j < w[i]){
        //この品物は入らない
        res = rec(i + 1, j);
    } else{
        //入れない場合と入れる場合を両方試す
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

int main(void){
    cout << rec(0, W) << endl;
    return 0;
}