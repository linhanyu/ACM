//
// Created by Henry on 17/1/29.
//

#include <cstdio>
#include <memory.h>

const int MAXN = 1000000 + 10;

struct edge{
    int v,next;
}G[MAXN<<1];

int n,head[MAXN],cur,ans;
bool color[MAXN];

int dfs(int u,int f){
    int son = 0;
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;
        son += dfs(G[i].v,u);
    }

    if (son >= 2){
        ans += son-1;
        if (u == 1) ans--;
        return 0;
    }

    return 1;
}

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedge(int u,int v){
    addedge_(u,v);
    addedge_(v,u);
}

void init(){
    memset(color,0, sizeof(color));
    memset(head,-1, sizeof(head));
    ans = cur = 0;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        init();
        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        dfs(1,0);
        printf("%d\n",(ans<<1) + 1 );
    }
 }
