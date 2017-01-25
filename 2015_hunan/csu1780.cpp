//
// Created by Henry on 17/1/18.
//

#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

const int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int MAXN = 500 + 10;
const int INF = 0x3f3f3f3f;
struct node{
    int x,y,d,dist;
    node(int x,int y,int d,int dist):x(x),y(y),d(d),dist(dist){}
    bool operator<(const node & n) const {
        return dist > n.dist;
    }
};

int Map[MAXN][MAXN];
int n,m;

bool outbound(int x,int y){
    return x <= 0 || y <= 0 || x>n || y >m;
}

int f_spfa(int sx,int sy,int tx,int ty){
    bool vis[MAXN][MAXN][4];
    int dist[MAXN][MAXN][4];

    memset(vis,0, sizeof(vis));
    memset(dist,0x3f, sizeof(dist));

    priority_queue<node> Q;
    for (int i = 0; i < 4; ++i) {
        dist[sx][sy][i] = Map[sx][sy];
    }

    for (int i = 0; i < 4; ++i) {
        int dx = sx + dir[i][0];
        int dy = sy + dir[i][1];

        if (outbound(dx,dy) || !Map[dx][dy]) continue;
        dist[dx][dy][i] = Map[sx][sy] + Map[dx][dy];
        Q.push(node(dx,dy,i,dist[dx][dy][i]));

    }


    while (!Q.empty()){
        node s = Q.top();

//        if (s.x == tx && s.y==ty) return s.dist;
        Q.pop();
        if (vis[s.x][s.y][s.d]) continue;
        vis[s.x][s.y][s.d] = true;

        for (int i = 0; i < 4; ++i) {
            if(i == s.d) continue;
            //f=1,有趣问题
            int dx = s.x + dir[i][0];
            int dy = s.y + dir[i][1];

            if (outbound(dx,dy) || !Map[dx][dy] || dist[dx][dy][i] < s.dist + Map[dx][dy]) continue;
            dist[dx][dy][i] = s.dist + Map[dx][dy];
            Q.push(node(dx,dy,i,dist[dx][dy][i]));

        }
    }

    int ans = INF;
    for (int i=0;i < 4;i++){
        ans = min(ans,dist[tx][ty][i]);
    }
    return ans < INF ? ans:-1;
}

struct node2{
    int x,y,dist;
    node2(int x,int y,int dist):x(x),y(y),dist(dist){}
    bool operator<(const node2 & n) const {
        return dist > n.dist;
    }
};
int spfa(int sx,int sy,int tx,int ty){
    bool vis[MAXN][MAXN];
    int dist[MAXN][MAXN];

    memset(vis,0, sizeof(vis));
    memset(dist,0x3f, sizeof(dist));

    priority_queue<node2> Q;
    dist[sx][sy] = Map[sx][sy];
    Q.push(node2(sx,sy,dist[sx][sy]));


    while (!Q.empty()){
        node2 s = Q.top();

//        if (s.x == tx && s.y==ty) return s.dist;
        Q.pop();
        if (vis[s.x][s.y]) continue;
        vis[s.x][s.y] = true;

        for (int i = 0; i < 4; ++i) {
            int dx = s.x + dir[i][0];
            int dy = s.y + dir[i][1];

            if (outbound(dx,dy) || !Map[dx][dy] || dist[dx][dy] < s.dist + Map[dx][dy]) continue;
            dist[dx][dy] = s.dist + Map[dx][dy];
            Q.push(node2(dx,dy,dist[dx][dy]));

        }
    }

    return dist[tx][ty] < INF ? dist[tx][ty]:-1;
}


char str[10];

int main(){
    int r1,r2,c1,c2;
//    int Map[MAXN][MAXN];
    int cases = 0;
    while (~scanf("%d%d%d%d%d%d",&n,&m,&r1,&c1,&r2,&c2)){
        printf("Case %d: ",++cases);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%s",str);
                if (str[0] == '*') Map[i][j] = 0;
                else sscanf(str,"%d",&Map[i][j]);
            }
        }

        printf("%d %d\n",spfa(r1,c1,r2,c2),f_spfa(r1,c1,r2,c2));
    }
}