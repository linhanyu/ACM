//
// Created by Henry on 16/10/23.
//
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXE = 360000;
const int MAXV = 2600;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;

struct edge{
    int v,cap, cost,next;
}G[MAXE];

int head[MAXV];
int dist[MAXV];
int preve[MAXV];
int z[MAXN][MAXN];
int cur,n,m;



void add_Edge(int u,int v,int cap,int cost){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addEdge(int u,int v,int cap,int cost) {
    add_Edge(u,v,cap,cost);
    add_Edge(v,u,0,-cost);
}

bool relexAble(int u,int e,int & relax){
    relax = dist[u] + G[e].cost ;
    return G[e].cap > 0 && relax < dist[G[e].v];
}

int spfa(int s,int end){
    static bool outqueue[MAXV];

    memset(outqueue,1, sizeof(outqueue));
    memset(dist,0x3f, sizeof(dist));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        outqueue[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next){
            int relax;

            if (relexAble(s,i,relax)){
                dist[G[i].v] = relax;
                preve[G[i].v] = i;

                if (outqueue[G[i].v]){
                    Q.push(G[i].v);
                    outqueue[G[i].v] = false;
                }
            }


        }

    }

    return dist[end] == INF ? -1 : dist[end];
}

int minCostFlow(int s,int t,int f){
    int res = 0;
    while (f > 0 && ~spfa(s,t)){
        int flow = INF;
        for (int i = t; i != s ; i = G[preve[i] ^ 1].v) {
            flow = min(flow,G[preve[i]].cap);
        }

        res += flow * dist[t];
        f -= flow;

        for (int i = t; i != s; i = G[preve[i] ^ 1].v) {
            G[preve[i]].cap -= flow;
            G[preve[i]^1].cap += flow;
        }
    }
    return res;
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

void solve(){
    init();
    //0~n-1 : toy
    //n~2n-1: fac1-toy1~n
    //mn~ m+1(n-1) - 1:facm-toy1~n
    //
    int src = n+n*m,dst = src + 1;

    for (int i = 0; i < n; ++i) {
        addEdge(src,i,1,0);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            addEdge(n + i*n + j,dst,1,0);
            for (int k = 0; k < n; ++k) {
                addEdge(k,n + n*i + j ,1,z[k][i] * (j+1));
            }
        }
    }

    printf("%.6lf\n",(double)minCostFlow(src,dst,n)/n);
}

int main(){
    int cases;
    scanf("%d",&cases);
    while (cases--){

        scanf("%d %d",&n,&m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d",&z[i][j]);
            }
        }

        solve();
    }
}