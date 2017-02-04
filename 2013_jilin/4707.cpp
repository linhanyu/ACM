//
// Created by Henry on 17/1/29.
//

#include <cstdio>
#include <memory.h>

const int MAXN = 100000 + 10;

struct edge{
    int v,next;
}G[MAXN<<1];

int head[MAXN];
int cur;

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
    memset(head,-1, sizeof(head));
    cur = 0;
}

int dfs(int u,int f,int dep,int d){


    int ans = 0;
    if(dep > d) ans = 1;
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;
        ans += dfs(G[i].v,u,dep+1,d);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();
        int n,d;
        scanf("%d%d",&n,&d);

        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        printf("%d\n",dfs(0,0,0,d));
    }
}