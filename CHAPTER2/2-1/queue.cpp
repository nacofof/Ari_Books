//キューのチュートリアル
#include <queue>
#include <iostream>
using namespace std;

int main(void){
    queue<int> que;          //int型をデータとするキューを用意
    que.push(1);             //{} -> {1}
    que.push(2);             //{1} -> {1,2}
    que.push(3);             //{1,2} -> {1,2,3}
    cout<<que.front()<<endl;
    que.pop();               //一番下から取り除く{1,2,3} -> {2,3}
    cout<<que.front()<<endl;
    que.pop();              //{2,3} -> {3}
    cout<<que.front()<<endl;
    que.pop();              //[3] -> {}
    return 0;
}