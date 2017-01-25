//
// Created by Henry on 16/11/27.
//
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int MAXE = 800000 + 10;
const int MAXV = 200000 + 10;
const int INF = 0x3f3f3f3f;
int C,n,m;

struct edge{
    int v,cost,next;
}G[MAXE];

struct node{
    int dist,v;
};

int head[MAXV];
int dist[MAXV];
int layor[MAXV];
int cur;
bool Appear[MAXV];

void init(){
    memset(head,-1, sizeof(head));
    memset(Appear,0, sizeof(Appear));
    cur = 0;
}

struct cmp{
    bool operator()(const node & a,const node & b) const {
        return a.dist > b.dist;
    }
};

void addedge_(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v,int cost){
    addedge_(u,v,cost);
    addedge_(v,u,cost);
}


void dij(int begin){
    static bool vis[MAXV];

    memset(vis,0,sizeof(vis));
    memset(dist,0x3f, sizeof(dist));

    node s;
    s.v = begin;
    s.dist = 0;
    priority_queue<node,vector<node >,cmp> Q;
    Q.push(s);
    dist[s.v] = 0;

    while (!Q.empty()){
        s = Q.top();
        Q.pop();

        if (vis[s.v]) continue;
        vis[s.v] = true;


        for (int i = head[s.v]; ~i ; i = G[i].next) {
            int v = G[i].v;
            if (dist[v] > dist[s.v] + G[i].cost){
                node tmp;
                dist[v] = dist[s.v] + G[i].cost;
                tmp.dist = dist[v];
                tmp.v = v;
                Q.push(tmp);
            }
        }


    }

}




int main(){
    int t;
    scanf("%d",&t);

    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d: ",cases);
        scanf("%d%d%d",&n,&m,&C);

        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&layor[i]);
            Appear[layor[i]] = true;
        }

        for (int i = 1; i <= n ; ++i) {
            addedge_(layor[i] + n, i ,0);

            if (layor[i] == 1){
                if (Appear[2]) addedge_(i , n + 2 , C);
            } else if(layor[i] == n){
                if (Appear[n-1]) addedge_(i , n + n - 1 , C);
            } else{
                if (Appear[layor[i]+1]) addedge_(i, n + layor[i] + 1 , C);
                if (Appear[layor[i]-1]) addedge_(i, n + layor[i] - 1 , C);
            }
        }

        for (int i = 0; i < m; ++i) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);

        }

        dij(1);

        printf("%d\n",dist[n] >= INF ? -1 : dist[n]);
    }
}