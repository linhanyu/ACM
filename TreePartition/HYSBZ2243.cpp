//
// Created by Henry on 17/2/3.
//
#include <cstdio>
#include <algorithm>
#include <memory.h>

#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1

using namespace std;

const int MAXN = 100000 + 10;

struct edge{
    int v,next;
}G[MAXN<<1];

int A[MAXN],lsum[MAXN<<2],rsum[MAXN<<2],msum[MAXN<<2],col[MAXN<<2],id[MAXN],dep[MAXN],top[MAXN],fa[MAXN],siz[MAXN],son[MAXN],head[MAXN],val[MAXN];
int cur,idx;

void init(){
    memset(head,-1, sizeof(head));
    siz[0] = cur = idx = 0;
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

void Cdfs(int u,int f,int d){
    son[u] = 0;
    fa[u] = f;
    dep[u] = d;
    siz[u] = 1;

    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;

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
        if (son[u] == G[i].v || fa[u] == G[i].v)continue;
        Ldfs(G[i].v,G[i].v);
    }
}

void pushUp(int rt){
    lsum[rt] = lsum[L];
    rsum[rt] = rsum[R];
    msum[rt] = msum[L] + msum[R];
    if (lsum[R] == rsum[L]) msum[rt]--;
}

void pushDown(int l,int r,int rt){
    if(~col[rt]) {
        lsum[L] = lsum[R] = rsum[L] = rsum[R] = col[rt];
        msum[L] = msum[R] = 1;
        col[L] = col[R] = col[rt];
        col[rt] = -1;
    }
}

void build(int l,int r,int rt){
    col[rt] = -1;
    if(l == r){
        lsum[rt] = rsum[rt]  = val[l];
        msum[rt] = 1;
        return;
    }
    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int key,int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        col[rt] = lsum[rt] = rsum[rt] = key;
        msum[rt] = 1;
        return;
    }

    pushDown(l,r,rt);
    int mid = MID;

    if (mid >= LB) update(key,LB,RB,lson);
    if (mid <  RB) update(key,LB,RB,rson);
    pushUp(rt);
}

int query(int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        return msum[rt];
    }

    pushDown(l,r,rt);
    int mid = MID;
    if (mid < LB) return query(LB,RB,rson);
    else if (mid >= RB) return query(LB,RB,lson);
    else{
        int ans = query(LB,RB,lson) + query(LB,RB,rson);
        if (rsum[L] == lsum[R]) ans--;
        return ans;
    }

}

int queryColor(int pos,int l,int r,int rt){
    if(l == r){
        return lsum[rt];
    }
    pushDown(l,r,rt);
    int mid = MID;

    if (pos <= mid) return queryColor(pos,lson);
    else return queryColor(pos,rson);
}

void parUpdate(int x,int y,int val){
    int tp1 = top[x],tp2 = top[y];

    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1,tp2);
            swap(x,y);
        }

        update(val,id[tp1],id[x],1,idx,1);
        x = fa[tp1];
        tp1 = top[x];
    }

    if (dep[x] < dep[y]) swap(x,y);
    update(val,id[y],id[x],1,idx,1);
}

int parQuery(int x,int y){
    int tp1 = top[x],tp2 = top[y],u = x,v = y;
    int ans = 0;
    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1,tp2);
            swap(x,y);
        }

        ans += query(id[tp1],id[x],1,idx,1);
        x = fa[tp1];
        tp1 = top[x];
    }

    if (dep[x] < dep[y]) swap(x,y);
    ans += query(id[y],id[x],1,idx,1);

    if (top[u] == top[v]) return ans;//本来就在一条链

    //爬树
    int tpu = top[u];
    while (tpu != tp1){
        int f = fa[tpu];
        int c1 = queryColor(id[f],1,idx,1);
        int c2 = queryColor(id[tpu],1,idx,1);
        if (c1 == c2) ans--;

        tpu = top[f];
    }

    int tpv = top[v];
    while (tpv != tp2){
        int f = fa[tpv];
        int c1 = queryColor(id[f],1,idx,1);
        int c2 = queryColor(id[tpv],1,idx,1);

        if (c1 == c2) ans--;
        tpv = top[f];
    }

    return ans;


}

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&A[i]);
        }

        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);

        for (int i = 1; i <= n; ++i) {
            val[id[i]] = A[i];
        }
        build(1,idx,1);

        char op[10];
        while (m--){
            scanf("%s",op);

            if (op[0] == 'Q'){
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n",parQuery(a,b));
            } else{
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                parUpdate(a,b,c);

            }
        }
    }
}