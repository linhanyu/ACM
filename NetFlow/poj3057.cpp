//
// Created by Henry on 16/10/4.
//
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int offset[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
const int MAXX = 15;
const int MAXE = 2000000;
const int MAXV = 20005;

struct Node{
    int to, next;
}Buffer[MAXE];

int cur;
int d,p;
int x,y;

char map[MAXX][MAXX];
int dist[MAXX][MAXX][MAXX][MAXX];
//x1,y1到x2,y2的最短距离

vector<int> dx,dy;
//door
vector<int> px,py;
//

int match[MAXV];
int head[MAXV];

bool used[MAXV];

void addNode(int u,int v){
    Buffer[cur].to = v;
    Buffer[cur].next = head[u];
    head[u] = cur++;

    Buffer[cur].to = u;
    Buffer[cur].next = head[v];
    head[v] = cur++;
}

bool dfs(int u){
    used[u] = true;

    for (int i = head[u]; ~i  ; i = Buffer[i].next) {
        int v = Buffer[i].to;
        int w = match[v];
        if (w < 0 || !used[w] && dfs(w)){
            match[u] = v;
            match[v] = u;

            return true;
        }
    }


    return false;
}

void bipartiteMatchJudge(int begin,int end,int Maxmatch){
    memset(match,-1, sizeof(match));

    int res=0;
    for (int i = begin; i <= end; ++i) {
        memset(used,0, sizeof(used));
        if (dfs(i)) {
            if (++res == Maxmatch) {
                printf("%d\n",i/d + 1);
                return;
            }
        }
    }
    puts("impossible");
}



bool inbound(int r,int c){
    return r>=0 && c>=0 && r<x && c<y;
}

void BFS(int beginx,int beginy,int d[MAXX][MAXX]){
    queue<int > qx,qy;

    d[beginx][beginy] = 0;
    qx.push(beginx);
    qy.push(beginy);

    while(!qx.empty()){
        int sx,sy;
        sx = qx.front();
        sy = qy.front();
        qx.pop();
        qy.pop();

        for (int i = 0; i < 4; ++i) {
            int dx = sx + offset[i][0];
            int dy = sy + offset[i][1];

            if (inbound(dx,dy) && d[dx][dy] < 0 && map[dx][dy] == '.'){
                d[dx][dy] = d[sx][sy] + 1;
                qx.push(dx);
                qy.push(dy);
            }
        }

    }
}
void init(){
    dx.clear();
    dy.clear();
    px.clear();
    py.clear();
    cur = 0;


    memset(head,-1, sizeof(head));
    memset(dist,-1, sizeof(dist));

}



void solve(){
    int n = x*y;
    init();

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (map[i][j] == 'D'){
                dx.push_back(i);
                dy.push_back(j);
                BFS(i,j,dist[i][j]);
            } else if (map[i][j] == '.'){
                px.push_back(i);
                py.push_back(j);
            }
        }
    }

    d = dx.size(),p=px.size();
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < p; ++j) {
            if (dist[dx[i]][dy[i]][px[j]][py[j]] >= 0){
                for (int k = dist[dx[i]][dy[i]][px[j]][py[j]]; k <= n; ++k) {
                    addNode((k-1)*d + i,n*d+j);
                }
            }
        }
    }

    if (p == 0){
        puts("0");
        return;
    }

    bipartiteMatchJudge(0,d*n-1,p);

}

int main(){
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&x,&y);

        for (int i = 0; i < x; ++i) {
            scanf("%s",map[i]);
        }

        solve();
    }
}

