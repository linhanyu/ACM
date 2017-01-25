//
// Created by Henry on 16/9/7.
//

#include <iostream>
#include <queue>
const int MAXH = 41;

const int offset[][2] = {{0,-1},{-1,0},{0,1},{1,0}};
//朝向:0->左,1->上,2->右:,3->下

using namespace std;

char map[MAXH][MAXH];
int cases,r,c;
bool inside(int row,int col){
    return row>=0 && row < r && col >= 0 && col < c;
}

char target;
int dfs(int r,int c,int dir){
    //每次强行左转
    if(map[r][c] == target) return 1;

    dir = (dir+3)%4;
    //优先左转
    for (int i = 0; i < 4; ++i) {
        int dr = r + offset[(dir + i)%4][0];
        int dc = c + offset[(dir + i)%4][1];

        if (inside(dr,dc) && map[dr][dc] != '#'){
            return dfs(dr,dc,dir+i) + 1;
        }
    }



//        if(!inside(dr,dc) || map[dr][dc] == '#' ){
//            //前边有墙,右转
//            dir = (dir+1)%4;
//
//        } else{
//            //前边没墙
//            if(map[wallr][wallc] != '#'){
//                //左边也没墙,左转一次
//                dir = (dir+3)%4;
//                dr = r + offset[dir][0];
//                dc = c + offset[dir][1];
//            }
//
//            return 1+dfsleft(dr,dc,dir);
//
//        }
}

int bfs(int beginr,int beginc,int endr,int endc){
    static int dis[MAXH][MAXH];
    static bool vis[MAXH][MAXH];

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            vis[i][j] = false;
        }
    }
    queue<int> Qr;
    queue<int> Qc;
    Qr.push(beginr);
    Qc.push(beginc);
    dis[beginr][beginc] = 1;
    vis[beginr][beginc] = true;

    while (!Qc.empty()){
        int sr = Qr.front();
        int sc = Qc.front();
        Qr.pop();
        Qc.pop();

        for (int i = 0; i < 4; ++i) {
            int dr = sr + offset[i][0];
            int dc = sc + offset[i][1];

            if (inside(dr,dc) && !vis[dr][dc] && map[dr][dc] != '#'){
                dis[dr][dc] = dis[sr][sc] + 1;
                vis[dr][dc] = true;

                Qr.push(dr);
                Qc.push(dc);
            }
        }
    }

    return dis[endr][endc];




}

int main(){
    cin>>cases;
    while (cases--){
        cin>>c>>r;
        int startr,startc,endr,endc;
        for (int i = 0; i < r; ++i) {
            cin>>map[i];
            int begin = strchr(map[i],'S')-map[i];
            int end = strchr(map[i],'E')-map[i];
            if (begin < c && begin>=0){
                startc = begin;
                startr = i;
            }

            if (end < c && end>=0){
                endc = end;
                endr = i;
            }
        }
        target = 'E';
        printf("%d ",dfs(startr,startc,0));
        target = 'S';
        printf("%d ",dfs(endr,endc,0));
        printf("%d\n",bfs(startr,startc,endr,endc));

    }
}