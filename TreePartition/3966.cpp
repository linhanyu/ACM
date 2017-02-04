//
// Created by Henry on 17/2/2.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define lowbit(a) (a&-a)

using namespace std;

const int MAXN = 50000 + 10;

struct edge{
    int v,next;
}G[MAXN << 1];

int T[MAXN<<2],son[MAXN],fa[MAXN],siz[MAXN],head[MAXN],id[MAXN],dep[MAXN],top[MAXN],A[MAXN];
int cur,idx,n,m,p;

void Cdfs(int u,int f,int d){
    son[u] = 0;
    fa[u] = f;
    siz[u] = 1;
    dep[u] = d;

    for (int i = head[u]; ~i ; i = G[i].next) {
        if(G[i].v == f) continue;

        Cdfs(G[i].v,u,d+1);
        siz[u] += siz[G[i].v];
        if (siz[son[u]] < siz[G[i].v]) son[u] = G[i].v;
    }
}

void Ldfs(int u,int tp){
    top[u] = tp;
    id[u] = ++idx;
    if (son[u]) Ldfs(son[u],tp);

    for (int i = head[u]; ~i; i = G[i].next) {
        if (fa[u] == G[i].v || son[u] == G[i].v) continue;
        Ldfs(G[i].v,G[i].v);
    }
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
    memset(head,-1, sizeof(head));
    memset(T,0, sizeof(T));
    siz[0] = cur = idx = 0;
}

void add(int pos,int val){
    while (pos){
        T[pos] += val;
        pos -= lowbit(pos);
    }
}

int query(int pos){
    int ans = 0;
    while (pos <= idx){
        ans += T[pos];
        pos += lowbit(pos);
    }
    return ans;
}

void update( int x,int y,int tp1,int tp2,int val){
    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1,tp2);
            swap(x,y);
        }

        add(id[x],val);
        add(id[tp1] - 1,- val);
        x = fa[tp1];
        tp1 = top[x];
    }
    if (dep[x] < dep[y]) swap(x,y);

    add(id[x],val);
    add(id[y] - 1,- val);
}

int main(){
    while (~scanf("%d%d%d",&n,&m,&p)){
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
        }

        for (int i = 0; i < m; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);

        for (int i = 1; i <= n; ++i) {
            add(id[i],A[i-1]);
            add(id[i]-1,-A[i-1]);
        }

        char op[5];
        while (p--){
            scanf("%s",op);
            int u,v,c;

            if (op[0] == 'Q'){
                scanf("%d",&u);
                printf("%d\n",query(id[u]));
            } else if (op[0] == 'I'){
                scanf("%d%d%d",&u,&v,&c);
                update(u,v,top[u],top[v],c);
            } else{
                scanf("%d%d%d",&u,&v,&c);
                update(u,v,top[u],top[v],-c);
            }
        }
    }
}