//再帰関数のチュートリアル
#include<iostream>
#define MAX_N 1000000
using namespace std;

long long memo[MAX_N];

long long fib(int n){
    if (n <= 1) return n;
    if(memo[n] != 0)return memo[n];
    return memo[n] = fib(n -1) + fib(n - 2);
}

int main(){
    int n = 100;
    cout << fib(n) <<endl;
    return 0;
}