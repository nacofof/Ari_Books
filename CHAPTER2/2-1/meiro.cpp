//p37
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

const int INF = 100000000;
//状態を表すクラスpairの場合，typedefしておくと便利
typedef pair<int, int> P;

//入力
int N = 10, M = 10;
int sx = 1, sy = 0;         //startの座標
int gx = 8, gy = 9;         //goalの座標
int d[MAX][MAX];    //各店までの最短距離の配列
char map[MAX][MAX] = {{'#','S','#','#','#','#','#','#','.','#'},
                          {'.','.','.','.','.','.','#','.','.','#'},
                          {'.','#','.','#','#','.','#','#','.','#'},
                          {'.','#','.','.','.','.','.','.','.','.'},
                          {'#','#','.','#','#','.','#','#','#','#'},
                          {'.','.','.','.','#','.','.','.','.','#'},
                          {'.','#','#','#','#','#','#','#','.','#'},
                          {'.','.','.','.','#','.','.','.','.','.'},
                          {'.','#','#','#','#','.','#','#','#','.'},
                          {'.','.','.','.','#','.','.','.','G','#'},};  //迷路

//4方向の移動ベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

//{sx, sy} -> {gx, gy}への最短距離を求める
//たどり着けないとINF
int bfs(){
    queue<P> que;
    //すべての点をINFで初期化
    for(int i = 0; i< N;i++)
        for(int j = 0; j < M; j++) d[i][j] = INF;
    //スタート地点をキューに入れ，その点の0にする
    que.push(P(sx,sy));
    d[sx][sy] = 0;

    //queが空になるまでループ
    while (que.size()){
        //キューの先頭を取り出す
        P p = que.front(); que.pop();
        //取り出してきた状態がゴールなら探索をやめる
        if(p.first == gx && p.second == gy) break;

        //移動4方向をループ
        for(int i = 0; i < 4; i++){
            //移動した後の点を(nx, ny) とする
            int nx = p.first + dx[i], ny = p.second + dy[i];

            //移動か可能かの判定とすでに訪れたことがあるかの判定（d[nx][ny] != なら訪れたことがある
            if(0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] != '#' && d[nx][ny] == INF){
                //移動できるならキューに入れ，その点の距離をpからの距離+1で確定する
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main(void){
    int res = bfs();
    cout << res << endl;
    return 0;
}