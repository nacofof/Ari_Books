//stackのチュートリアル
#include <stack>
#include <iostream>

using namespace std;

int main(void){
    stack<int> s;   //int型をデータとするスタックを用意
    s.push(1);      //{} -> {1}
    s.push(2);      //{1} -> {1,2}
    s.push(3);      //{1,2} -> {1,2,3}
    cout << s.top() << endl;
    s.pop();        //一番上から取り除く{1,2,3} -> {1,2}
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    return 0;
}