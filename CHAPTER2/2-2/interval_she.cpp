//p43~ 空間スケジューリング問題
#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;

//入力
int n = 5, S[MAX_N] = {1, 2, 4, 6, 8}, T[MAX_N] = {3, 5, 7, 9, 10};

//仕事をソートするためのpairの配列
pair<int, int> itv[MAX_N];

int main(void){
    //pairは辞書順で比較される
    //終了時間の早い順に比較したいため，Tをfirstに，Sをsecondに入れる
    for (int i = 0; i < n; i++){
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + n);

    //tは最後に選んだ仕事の終了時間
    int ans = 0, t = 0;
    for (int i = 0; i < n; i++){
        if(t < itv[i].second){
            ans++;
            t = itv[i].first;
        }
    }
    printf("%d\n", ans);
    return 0;
}