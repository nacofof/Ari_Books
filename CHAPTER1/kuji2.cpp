//p27~
#include <algorithm>
#include <iostream>
#include <random>
#include <functional>
using namespace std;
#define MAX_N 1000000
#define MAX_NN 1000000000000
int n = 1000, m = 10204, k[MAX_N];

//２つで作れる数を格納する配列
int kk[MAX_NN];

//乱数の生成
void rand_num(void){
    random_device randomDevice;
    vector<uint32_t> randomSeedVector(1);
    generate(randomSeedVector.begin(),
    randomSeedVector.end(), ref(randomDevice));

    seed_seq randomSeed(randomSeedVector.begin(),
                            randomSeedVector.end());

    //エンジンを生成
    mt19937 randomEngine(randomSeed);

    //乱数をを1からnまでの整数にする
    uniform_int_distribution<int> randomIntDistribution(1,n);

    //配列に代入
    for(int i = 0; i < n; i++){
        k[i] = randomIntDistribution(randomEngine);
    }
}

//２分探索
bool binary_search(int x){
    //xが存在し得る範囲はkkkk1], kkkk[l + 1], ...., kkkk[r - 1]
    int l = 0, r = n;

    //範囲に何も含まれなくなるまで繰り返す
    while (r-l >= 1){
        int i = (l + r)/2;
        if (kk[i] == x) return true; //見つかった
        else if (kk[i] < x) i = i + 1;
        else r = i;
    }
    //見つからなかった
    return false;
}

int main (void){
    rand_num();
    //k[c] + k[d]の取り得る値を列挙
    for(int c = 0; c < n; c++){
        for (int d = 0; d < n; d++){
            kk[c * n + d] = k[c] + k[d];
        }
    }
    //２分探索を行うためにソート
    sort(kk, kk + n * n);

    bool f = false;

    for (int a;a < n; a++){
        for (int b; b < n; b++){
            //内側２つのループの代わりに２分探索
            if (binary_search(m - k[a] - k[b])){
                f = true;
            }
        }
    }
    if (f) puts("Yes");
    else puts("No");
    return 0;
}