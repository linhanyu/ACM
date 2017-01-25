//
// Created by Henry on 17/1/2.
//

#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;

const int MAXV = 1000 + 10;
const int MAXE = MAXV * MAXV * 4;
const int INF = 0x3f3f3f3f;

struct edge{
    int next,v,cap;
}G[MAXE];


int head[MAXV];
int dist[MAXV];
int pree[MAXV];
int cur;
int M,n,e,a,b,d;

void addedge_(int u,int v,int cap){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cap){
    addedge_(u,v,cap);
    addedge_(v,u,0);
}

int BFS(int s,int t){

    memset(dist,-1, sizeof(dist));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while(!Q.empty()){
        s = Q.front();
        if (s == t) return dist[t];
        Q.pop();

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (~dist[G[i].v] || !G[i].cap) continue;

            dist[G[i].v] = dist[s] + 1;
            pree[G[i].v] = i;
            Q.push(G[i].v);
        }
    }

    return -1;
}

int MaxFlow(int s,int t){
    int flow = 0;
    while (~BFS(s,t)){
        int f = INF;
        for (int i = t; i != s ; i = G[pree[i] ^ 1].v) {
            f = min(f,G[pree[i]].cap);
        }
        M = max(f,M);
        flow += f;
        for (int i = t; i != s ; i = G[pree[i] ^ 1].v) {
            G[pree[i]].cap -= f;
            G[pree[i] ^ 1].cap += f;
        }
    }

    return flow;
}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
    M = 0;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();
        scanf("%d%d%d%d%d",&d,&n,&e,&a,&b);
        while (e--){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }

        int ans = MaxFlow(a,b);

        printf("%d %.3f\n",d,(float)ans/M);
    }
}