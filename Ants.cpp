//P23~
//最小の時間：すべてのアリが近い方の端にむかって動くとき
//２匹のアリがぶつかるとき，２匹のアリはそのまますれ違ったように見えるので，
//最大の時間：端までの距離の最大値を求めればよい
#include<cstdio>
#include<algorithm>
const int MAX_N = 1000000;
const int MAX_L = MAX_N;
int L = 10;
int n = 3;
int x[MAX_N] = {2,6,7};

using namespace std;
int main(void){
    int ans = 0;
    int max_ans = 0;
    int min_ans = 0;

    //最小の時間を計算
    for (int i = 0; i < n; i++){
        ans = min(x[i], L - x[i]);
        min_ans = max(ans, min_ans);
    }
    //最大の時間を計算
    for(int i = 0; i < n; i++){
        ans = max(x[i], L - x[i]);
        max_ans = max(ans, max_ans);
    }
    printf("max : %d\n", max_ans);
    printf("min : %d\n", min_ans);
}