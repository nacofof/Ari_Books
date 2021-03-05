//p42~ 硬貨の問題
#include<iostream>
#define MAX_N 1000000000
using namespace std;

//コインの金額
const int V[6] = {1, 5, 10, 50, 100, 500};

//入力
int C[6] = {3, 2, 1, 3, 0, 2};       //コインの枚数：C[0] = 1, C[1] = 5, C[2] = 10, C[3] = 50, C[4] = 50, C[5] = 100, C[6] = 500
int A = 620;

int main(void){
    int ans = 0;
    for (int i = 5; i >= 0; i--){
        int t = min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    cout << ans << endl;
    return 0;
}