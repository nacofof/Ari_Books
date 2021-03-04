//順列のチュートリアル
#include<iostream>
#include<algorithm>
#define MAX_N 1000000
using namespace std;

bool used[MAX_N];
int perm[MAX_N];
//{0,1,2,3,4, ... ,n -1}の並び替えn!通りを生成する
void permutation1(int pos, int n){
    if (pos == n){
        for (int i = 0; i < n;i++)
            cout << perm[i];
        cout << endl;
        return;
    }

    //permのpos番目を0~n-1のどれにするかのループ
    for (int i = 0; i < n; i++){
        if (!used[i]){
            perm[pos] = i;
            //iを使ったのでフラグをtrueにしておく
            used[i] = true;
            permutation1(pos + 1, n);
            //戻ってきたらフラグを戻しておく
            used[i] = false;
        }
    }
    return;
}

//重複があってもすべての順列を生成する
//nesxt_permutationは辞書順で次の順列を生成する
int perm2[MAX_N];

void permutation2(int n){
    for (int i = 0; i < n; i++){
        perm2[i] = i;
    }
    do {
        for (int i = 0; i < n; i++)
            cout << perm2[i];
        cout << endl;
    } while (next_permutation(perm2, perm2 + n));
    //全ての順列を生成し終わったらnext_permutationはfalseを返す
    return;
}

int main(void){
    permutation1(2, 3);
    cout << endl;
    permutation2(3);
    return 0;
}