//p49~
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20000
#define MAX_L 50000
typedef long long ll;

//入力
int N = 3, L[MAX_N] = {8, 5, 8};

int main(void){
    ll ans = 0;

    //板が１枚になるまで適用
    while (N > 1){
        //一番短い板mii1，次に短い板mii2を求める
        int mii1 = 0, mii2 = 1;
        if(L[mii1] > L[mii2]) swap(mii1, mii2);

        for (int i = 2; i < N; i++){
            if(L[i] < L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }
            else if (L[i] < L[mii2])
                mii2 = i;
        }

        //それらを併合
        int t = L[mii1] + L[mii2];
        ans += t;

        if(mii1 == N - 1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N - 1];
        N--;
    }
    cout << ans << endl;
}