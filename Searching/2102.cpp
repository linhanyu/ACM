//
// Created by Henry on 16/9/21.
//
#include <cstdio>
#include <memory>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = -1;
const int MAXN = 11;
const int offset[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct node{
    int i;
    int j;
    int layer;

    node(){}
    node(int layer,int i,int j):i(i),j(j),layer(layer){}
};
int t,m,n;
char Graph[2][MAXN][MAXN];
int dis[2][MAXN][MAXN];

bool outbound(int i,int j){
    return i<0 || i>=n || j<0 || j>=m;
}

bool inbound(int i){
return i>=0 && i<m;
}

bool bfs(node begin){
    queue<node> Q;
    memset(dis,-1, sizeof(dis));
    dis[begin.layer][begin.i][begin.j] = 0;

    Q.push(begin);

    while (!Q.empty()){
        node source = Q.front();

        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int di = source.i + offset[i][0];
            int dj = source.j + offset[i][1];
            int dlayer = source.layer;

            if (outbound(di,dj))continue;

            if (Graph[dlayer][di][dj] == '#') dlayer = !dlayer;
            //奇妙传送
            if (Graph[dlayer][di][dj] == '*' || dis[dlayer][di][dj] != INF || (Graph[0][di][dj] == '#' && Graph[1][di][dj] == '#')) continue;



            dis[dlayer][di][dj] = dis[source.layer][source.i][source.j] + 1;

            if (dis[dlayer][di][dj]>t)return false;

            if (Graph[dlayer][di][dj] == 'P') return true;


            Q.push(node(dlayer,di,dj));


        }


    }

    return false;

}


int main(){
    int cases,begini,beginj;
    cin>>cases;
    while(cases--){
        cin>>n>>m>>t;
        begini = -1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>Graph[i][j];

            }
        }

        if ( bfs(node(0,0,0))){
            puts("YES");
        } else{
            puts("NO");
        }

    }
}
