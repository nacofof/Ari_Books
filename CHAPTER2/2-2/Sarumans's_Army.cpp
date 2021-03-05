#include<iostream>

#define MAX_N 1000
using namespace std;

//入力
int N = 6, R = 10, X[MAX_N] = {1, 7, 15, 20, 30, 50};

int main(void){
    int i = 0, ans = 0;
    while(i < N){
        //sはカバーされていない一番左の点の位置
        int s = X[i++];
        //sから距離Rを超える点まで進む
        while(i < N && X[i] <= s + R) i++;

        //pは新しく点をつける位置
        int p = X[i - 1];
        //pから距離Rを超える点まで進む
        while(i < N && X[i] <= p + R) i++;

        ans++;
    }
    cout << "ans = " << ans << endl;
    return 0;
}