//
// Created by Henry on 17/1/28.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1
using namespace std;

const int MAXN =  100000 + 10;

struct edge{
    int v,next;
}G[MAXN << 1];

struct e{
    int x,y,c;
}E[MAXN];

int size[MAXN],T[MAXN<<2],son[MAXN],fa[MAXN],id[MAXN],dep[MAXN],head[MAXN],top[MAXN],val[MAXN];
int cur,idx;


void Cdfs(int u,int f,int d){
    size[u] = 1;
    son[u] = 0;
    fa[u] = f;
    dep[u] = d;

    for (int i = head[u]; ~i  ; i = G[i].next) {
        if (f == G[i].v)continue;
        Cdfs(G[i].v,u,d+1);
        size[u] += size[G[i].v];
        if (size[son[u]] < size[G[i].v])son[u] = G[i].v;
    }
}

void Ldfs(int u,int tp){
    top[u] = tp;
    id[u] = ++idx;

    if (son[u]) Ldfs(son[u],tp);
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == son[u] || fa[u] == G[i].v) continue;
        Ldfs(G[i].v,G[i].v);
    }
}

void init(){
    memset(head,-1, sizeof(head));
    idx = cur = 0;
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

void pushUp(int rt){
    T[rt] = T[L] + T[R];
}

void build(int l,int r,int rt){
    if (l == r){
        T[rt] = val[l];
        return;
    }

    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int pos,int val,int l,int r,int rt){
    if (l == r){
        T[rt] = val;
        return;
    }

    int mid = MID;
    if (pos <= mid) update(pos,val,lson);
    if (pos >  mid) update(pos,val,rson);
    pushUp(rt);
}

int query(int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        return T[rt];
    }

    int mid = MID;
    int ans = 0;
    if (mid >= LB) ans += query(LB,RB,lson);
    if (mid <  RB) ans += query(LB,RB,rson);
    return ans;
}

int main(){
    int n,q,s;
    while (~scanf("%d%d%d",&n,&q,&s)){
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].c);
            addedge(E[i].x,E[i].y);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);

        for (int i = 1; i < n; ++i) {
            if (dep[E[i].x] < dep[E[i].y]) swap(E[i].x,E[i].y);
            val[id[E[i].x]] =E[i].c;
        }

        build(1,idx,1);
        for (int i = 0; i < q; ++i) {
            int op,x,y;
            scanf("%d",&op);
            if (op){
                scanf("%d%d",&x,&y);
                update(id[E[x].x],y,1,idx,1);
            } else{
                scanf("%d",&x);

                int u = x,v = s;
                int ans = 0,tp1 = top[u],tp2 = top[v];

                while (tp1 != tp2){
                    if (dep[tp1]  < dep[tp2]){
                        swap(tp1,tp2);
                        swap(u,v);
                    }

                    ans += query(id[tp1],id[u],1,idx,1);
                    u = fa[tp1];
                    tp1 = top[u];
                }

                if (u != v) {
                    if (dep[u] < dep[v]) swap(u, v);
                    ans += query(id[son[v]], id[u], 1, idx, 1);
                }
                s = x;

                printf("%d\n",ans);
            }
        }

    }
}