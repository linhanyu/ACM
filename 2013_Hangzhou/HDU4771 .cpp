//
// Created by Henry on 17/2/12.
//

#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

const int MAXN = 100 ;
const int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

char mp[MAXN][MAXN];
int trod[4][2];
int dist[MAXN][MAXN][1<<4];
int n,m,k;

struct node{
    int x,y,statu;
    node(){}
    node(int x,int y,int statu):x(x),y(y),statu(statu){}
};


bool outbound(int x,int y){
    return x >= n || y >= m || x < 0 || y < 0;
}

int BFS(int sx,int sy){

    memset(dist,-1, sizeof(dist));

    queue<node> Q;
    Q.push(node(sx,sy,0));
    dist[sx][sy][0] = 0;

    while (!Q.empty()){
        node s = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int dx = s.x + step[i][0];
            int dy = s.y + step[i][1];

            if (outbound(dx,dy) || mp[dx][dy] == '#' )continue;

            int ds = s.statu;
            for (int j = 0; j < k; ++j) {
                if (trod[j][0] == dx && trod[j][1] == dy) ds |= 1<<j;
            }

            if (~dist[dx][dy][ds]) continue;
            dist[dx][dy][ds] = dist[s.x][s.y][s.statu] + 1;

            if(ds == (1<<k)-1) return dist[dx][dy][ds];
            Q.push(node(dx,dy,ds));
        }
    }
    return -1;
}

int main(){
//    char mp[MAXN][MAXN];
    while (~scanf("%d%d",&n,&m) && m && n){

        for (int i = 0; i < n; ++i) {
            scanf("%s",mp[i]);
        }

        scanf("%d",&k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d",&trod[i][0],&trod[i][1]);
            trod[i][0]--;
            trod[i][1]--;
        }

        int sx,sy;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == '@'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }

        printf("%d\n",BFS(sx,sy));
    }
}