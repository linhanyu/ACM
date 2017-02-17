//
// Created by Henry on 17/2/11.
//

#include <cstdio>
#include <memory.h>
typedef long long LL;

const int MAXN = 100000 + 10;

struct edge{
    int v,next;
}G[MAXN << 1];

int n,k,head[MAXN],w[MAXN];
bool vis[MAXN];
int cur;

void addedge_(int u,int v){
    G[cur].v  = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v){
    addedge_(u,v);
    addedge_(v,u);
}

void dfs(int u,int f){

    int heavy = -1;
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;

        dfs(G[i].v,u);

    }

    w[tar] = 0;
    return ans + w[u];
}

void init(){
    memset(head,-1, sizeof(head));
    memset(vis,0, sizeof(vis));
    cur = 0;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        init();
        printf("Case #%d: ",cases);
        scanf("%d%d",&n,&k);

        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&w[i]);
        }

        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        LL ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += dfs(1,0);
        }

        printf("%lld\n",ans);
    }
}