//p45~
#include<iostream>
using namespace std;

const int MAX_N = 1000000;
//入力
int N = 6;
char S[MAX_N + 1]={'A','C','D','B','C','B'};

int main(void){
    //S[a], S[a+1], ..., S[b]が残っている文字列
    int a = 0, b = N - 1;

    while(a <= b){
        //左から見た場合と右から見た場合を比較
        bool left = false;
        for (int i = 0; i < N; i++){
                if(S[a + i] < S[b - i]){
                    left = true;
                    break;
                }
                else if (S[a + i] > S[b - i]){
                    left = false;
                    break;
                }
        }
        if(left)
            putchar(S[a++]);
        else
            putchar(S[b--]);
    }
    puts("");
    return 0;
}