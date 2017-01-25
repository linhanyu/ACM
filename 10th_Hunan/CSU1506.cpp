//
// Created by Henry on 17/1/22.
//

#include<cstdio>
#include <memory.h>
#include <queue>

using namespace std;
const int MAXV = 1000;
const int MAXE = 100000;
const int INF = 0x3f3f3f3f;

struct edge{
    int v,cost,cap,next;
}G[MAXE];

int head[MAXV],dist[MAXV],pree[MAXV];
int cur,n,m;

void spfa(int s){
    int outQ[MAXV];

    memset(dist,0x3f, sizeof(dist));
    memset(outQ,1, sizeof(outQ));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        outQ[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (G[i].cap && dist[s] + G[i].cost < dist[G[i].v]){
                dist[G[i].v] = dist[s] + G[i].cost;
                pree[G[i].v] = i;

                if (outQ[G[i].v]){
                    outQ[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }
}

int MCMF(int s,int t,int f){
    int c = 0;
    while (f){
        spfa(s);

        int flow = INF;
        for (int i = t; i != s ; i = G[pree[i] ^ 1].v) {
            flow = min(flow, G[pree[i]].cap);
        }

        f -= flow;
        c += flow * dist[t];

        for (int i = t; i != s ; i = G[pree[i] ^ 1].v) {
            G[pree[i]].cap -= f;
            G[pree[i] ^ 1].cap += f;
        }
    }
    return c;
}

void addedge_(int u,int v,int cost,int cap){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cost,int cap){
    addedge_(u,v,cost,cap);
    addedge_(v,u,-cost,0);
}

void AddEdge(int u,int v,int di,int ai){
    addedge(u,v,di,1);
    addedge(u,v,di + ai,1);
}
void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

int main(){
    int cases = 0;
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i = 0; i < m; ++i) {
            int u,v,di,ai;
            scanf("%d%d%d%d",&u,&v,&di,&ai);
            AddEdge(u,v,di,ai);
        }

        if (n == 1) {
            printf("Case %d: %d\n",++cases,0);
            continue;
        }

        printf("Case %d: %d\n",++cases,MCMF(1,n,2));
    }
}