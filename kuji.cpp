//p25~
#include <algorithm>
#include <iostream>
#include <random>
#include <functional>
using namespace std;
#define MAX_N 1000000
int n = 1000, m = 10204, k[MAX_N];

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
    //xが存在し得る範囲はk[1], k[l + 1], ...., k[r - 1]
    int l = 0, r = n;

    //範囲に何も含まれなくなるまで繰り返す
    while (r-l >= 1){
        int i = (l + r)/2;
        if (k[i] == x) return true; //見つかった
        else if (k[i] < x) i = i + 1;
        else r = i;
    }
    //見つからなかった
    return false;
}

int main (void){
    rand_num();
    //２分探索を行うためにソート
    sort(begin(k), end(k));

    bool f = false;

    for (int a;a < n; a++){
        for (int b; b < n; b++){
            for (int c; c < n; c++){
                if (binary_search(m - k[a] - k[b] - k[c]))
                f = true;
            }
        }
    }
    if (f) puts("Yes");
    else puts("No");
    return 0;
}