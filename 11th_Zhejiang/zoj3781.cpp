//
// Created by Henry on 16/12/14.
//

#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;

const int MAXV = 2000;
const int MAXE = 10000;
const int INF = 0x3f3f3f3f;
const int step[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct edge{
    int next,v;
}G[MAXE];

bool rls[MAXV][MAXV];

char Map[MAXV][MAXV];
int pointHash[MAXV][MAXV];
int cur,n,m;
int head[MAXV];
int dist[MAXV];

bool inbound(int r,int c){
    return r >=0 && c >= 0 && r < n && c < m;
}

void addedge_(int u,int v){
    if (rls[u][v] || u == v) return;

    rls[u][v] = true;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(rls,0, sizeof(rls));
    memset(head,-1, sizeof(head));
    memset(pointHash,-1, sizeof(pointHash));
    cur = 0;
}

void dfs(int x,int y,int point){
    if(~pointHash[x][y])return;

    pointHash[x][y] = point;

    for (int i = 0; i < 4; ++i) {
        int dx = x + step[i][0];
        int dy = y + step[i][1];

        if (inbound(dx,dy) && Map[dx][dy] == Map[x][y]){
            dfs(dx,dy,point);
        }
    }
}

int BFS(int s){
    memset(dist,-1, sizeof(dist));

    queue<int > Q;
    dist[s] = 0;
    Q.push(s);

    int MaxDist = 0;
    while (!Q.empty()){
        s = Q.front();
        Q.pop();

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (~dist[G[i].v]) continue;

            dist[G[i].v] = dist[s] + 1;
            MaxDist = max(MaxDist,dist[G[i].v]);
            Q.push(G[i].v);
        }
    }

    return MaxDist;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();

        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++i) {
            scanf("%s",Map[i]);
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(~pointHash[i][j]) continue;
                dfs(i,j,cnt++);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int dx = i + step[k][0];
                    int dy = j + step[k][1];
                    if (inbound(dx,dy)){
                        addedge_(pointHash[i][j],pointHash[dx][dy]);
                    }
                }
            }
        }

        int Min = INF;
        for (int i = 0; i < cnt; ++i) {
            Min = min(Min,BFS(i));
        }

        printf("%d\n",Min);
    }
}