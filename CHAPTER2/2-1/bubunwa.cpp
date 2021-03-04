//p34~
#include <iostream>
#define MAX_N 1000000
using namespace std;

//入力
int a[MAX_N] = {1,2,4,7};
int n = 4, k = 13;

//iまででsumを作って，残りi以降を調べる
bool dfs(int i, int sum){
    //n個決め終わったら，今までの和sumがkと等しいかを返す
    if (i == n) return sum == k;
    //a[i]を使わない場合
    if (dfs(i + 1, sum)) return true;
    //a[i]を使う場合
    if (dfs(i + 1, sum + a[i])) return true;

    //a[i]を使う使わないに関わらずkが作れないのでfalseを返す
    return false;
}

int main(){
    if(dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}