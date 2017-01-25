//
// Created by Henry on 16/10/27.
//

#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXK = 10;
const int upBound = 1001 ;
const int INF = 0x3f3f3f3f;
const int step[] = {1,-1};
const int stepDFS[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int k,sx,sy,dx,dy,depth,MaxDepth;
int distx[upBound],disty[upBound],pipes[MAXK],pipesNUM[MAXK];

bool OutBound(int pos) {
    return pos <=0 || pos >= upBound;
}

bool OutBound(int x,int y) {
    return x <=0 || x >= upBound || y <= 0 || y>=upBound;
}

void BFS(int s,int dist[],int size){
    memset(dist,-1, size * sizeof(int));

    queue<int > Q;
    dist[s] = 0;
    Q.push(s);

    while (!Q.empty()){
        s = Q.front();
        Q.pop();

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2; ++j) {
                int d = s + pipes[i]*step[j];
                if (!OutBound(d) && !(~dist[d])){
                    dist[d] = dist[s] + 1;
                    Q.push(d);
                }
            }

        }
    }
}

bool DFS(int x,int y,int d){
    if (distx[x] == -1 || disty[y] == -1 || d + distx[x] + disty[y] > depth) return false;

    if (x == dx && y == dy) return true;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pipesNUM[i]){
                int dx = x + stepDFS[j][0] * pipes[i];
                int dy = y + stepDFS[j][1] * pipes[i];

                if (OutBound(dx,dy)) continue;

                pipesNUM[i]--;

                if (DFS(dx,dy,d+1)) return true;

                pipesNUM[i]++;
            }

        }

    }

    return false;
}

int idaStar(int sx,int sy){
    BFS(dx,distx,upBound);
    BFS(dy,disty,upBound);


    for (depth = 1; depth <= MaxDepth; ++depth) {
        if (DFS(sx,sy,0)) break;
    }

    return depth > MaxDepth ? -1:depth;
}

int main(){
    while (~scanf("%d%d%d%d%d",&sx,&sy,&dx,&dy,&k)){
        MaxDepth = 0;

        for (int i = 0; i <  k; ++i) {
            scanf("%d",&pipes[i]);
        }

        for (int i = 0; i < k; ++i) {
            scanf("%d",&pipesNUM[i]);
            MaxDepth += pipesNUM[i];
        }


        printf("%d\n",idaStar(sx,sy));
    }
}

//int dist[upBound][upBound];
//bool used[upBound][upBound];

//vector<int > pipes;
//
//int h(int x,int y){
//    return abs(dx - x) + abs(dy - y);
//}
//
//bool outBound(int x,int y){
//    return x > upBound || y>upBound || x<1 || y<1;
//}
//
////void BFS(int x,int y){
////    memset(dist,-1, sizeof(dist));
////
////    queue<int > Qx;
////    queue<int > Qy;
////
////    dist[]
////}
//
//void DFS(int x,int y,int d){
//    int t = h(x,y);
//
//    if (incLenth > t) incLenth = t;
//
//    if (t  > stopLenth) return;
//
//    if (!t){
//        //找到啦
//        ans = d;
//        return;
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < pipes.size(); ++j) {
//            int dx = x + pipes[j]*step[i][0];
//            int dy = y + pipes[j]*step[i][1];
//
//            if (outBound(dx,dy) || used[dx][dy]) continue;
//
//            used[dx][dy] = true;
//
//            DFS(dx,dy,d+1);
//            if (ans) return;
//
//            used[dx][dy] = false;
//        }
//    }
//
//}
//
//void idaStar(int sx,int sy,int stop){
//    stopLenth = h(sx,sy);
//
//    while (!ans && stopLenth <= stop ){
//        incLenth = INF;
//        DFS(sx,sy,0);
//        stopLenth = incLenth;
//    }
//
//}

//int main(){
//    while (~scanf("%d%d%d%d%d",&sx,&sy,&dx,&dy,&k)){
//        pipes.clear();
//        int tmp;
//        for (int i = 0; i < 2 * k; ++i) {
//            scanf("%d",&tmp);
//            pipes.push_back(tmp);
//        }
//        ans = 0;
//        idaStar(sx,sy,upBound);
//
//        printf("%d\n",ans?ans:-1);
//    }
//}