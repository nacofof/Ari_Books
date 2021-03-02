//3つの棒を選んだ際に，その３つの棒で三角形が作れる必要十分条件は
//最も長い棒の長さ<その他２つの棒の長さ
//となる

#include <cstdio>
#include <algorithm>
#define N 5

using namespace std;
int main(){
    int n;
    int a[N]={2,3,4,5,10};
    int i,j,k;
    int ans = 0;

    for(i=0;i<N;i++){
        for(j=i+1; j < N; j++){
            for(k=j+1;k<N;k++){
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i],max(a[j],a[k]));
                int rest = len - ma;

                if (ma < rest)
                ans = max(ans, len);
            }
        }
    }
    printf("%d\n", ans);
}