//
// Created by Henry on 17/2/2.
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

const int MAXN = 10010;
const int INF = 0x3f3f3f3f;

struct E{
    int u,v,val;
}edges[MAXN];

struct edge{
    int v,next;
}G[MAXN<<1];

int MaxT[MAXN<<2],MinT[MAXN<<2],head[MAXN],id[MAXN],son[MAXN],fa[MAXN],top[MAXN],dep[MAXN],siz[MAXN],val[MAXN];
int cur,idx;
bool col[MAXN<<2];

void Cdfs(int u,int f,int d){
    son[u] = 0;
    fa[u] = f;
    dep[u] = d;
    siz[u] = 1;

    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;

        Cdfs(G[i].v,u,d+1);
        siz[u] += siz[G[i].v];
        if (siz[son[u]] < siz[G[i].v])son[u] = G[i].v;
    }
}

void Ldfs(int u,int tp){
    top[u] = tp;
    id[u] = ++idx;
    if (son[u]) Ldfs(son[u],tp);

    for (int i = head[u]; ~i ; i = G[i].next) {
        if (son[u] == G[i].v || fa[u] == G[i].v) continue;
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

void pushUp(int rt){
    MaxT[rt] = max(MaxT[L],MaxT[R]);
    MinT[rt] = min(MinT[L],MinT[R]);
}

void rotate(int rt){
    MinT[rt] = -MinT[rt];
    MaxT[rt] = -MaxT[rt];
    swap(MinT[rt],MaxT[rt]);
}

void pushDown(int rt){
    if (col[rt]){
        rotate(L);
        rotate(R);
        col[rt] = 0;
        col[L] ^= true;
        col[R] ^= true;
    }
}

void build(int l,int r,int rt){
    col[rt] = false;
    if (l == r){
        MaxT[rt] = MinT[rt] = val[l];
        return;
    }
    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int pos,int key,int l,int r,int rt){
    if (l == r){
        MinT[rt] = MaxT[rt] = key;
        return;
    }

    pushDown(rt);
    int mid = MID;
    if (pos <= mid) update(pos,key,lson);
    else update(pos,key,rson);
    pushUp(rt);
}

void negUpdate(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        rotate(rt);
        col[rt] ^= 1;
        return;
    }

    pushDown(rt);
    int mid = MID;

    if (mid >= LB) negUpdate(LB,RB,lson);
    if (mid <  RB) negUpdate(LB,RB,rson);
    pushUp(rt);
}

int query(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return MaxT[rt];
    }

    pushDown(rt);
    int mid = MID,ans = -INF;

    if (mid >= LB) ans = max(ans,query(LB,RB,lson));
    if (mid <  RB) ans = max(ans,query(LB,RB,rson));

    return ans;
}

int parQuery(int x,int y){
    int tp1 = top[x],tp2 = top[y];
    int ans = -INF;
    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1,tp2);
            swap(x,y);
        }

        ans = max(ans,query(id[tp1],id[x],1,idx,1));
        x = fa[tp1];
        tp1 = top[x];
    }

    if (x == y) return ans;

    if (dep[x] < dep[y]) swap(x,y);
    ans = max(ans,query(id[son[y]],id[x],1,idx,1));

    return ans;
}


void parUpdate(int x,int y){
    int tp1 = top[x],tp2 = top[y];
    while (tp1 != tp2){
        if (dep[tp1] < dep[tp2]){
            swap(tp1,tp2);
            swap(x,y);
        }

        negUpdate(id[tp1],id[x],1,idx,1);
        x = fa[tp1];
        tp1 = top[x];
    }

    if (x == y) return ;

    if (dep[x] < dep[y]) swap(x,y);
    negUpdate(id[son[y]],id[x],1,idx,1);
}

void init(){
    memset(head,-1, sizeof(head));
    siz[0] = cur = idx = 0;
}


int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        init();

        int n;
        scanf("%d",&n);
        for (int i = 1 ; i < n; ++i) {
            scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].val);
            addedge(edges[i].u,edges[i].v);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);

        for (int i = 1; i < n; ++i) {
            if (dep[edges[i].u] < dep[edges[i].v]) swap(edges[i].u,edges[i].v);
            val[id[edges[i].u]]= edges[i].val;
        }

        build(1,idx,1);
        char op[20];
        for (;;) {
            int u,v;
            scanf("%s",op);
            if (op[0] == 'D') break;
            else if (op[0] == 'Q'){
                scanf("%d%d",&u,&v);
                printf("%d\n",parQuery(u,v));
            } else if (op[0] == 'C'){
                scanf("%d%d",&u,&v);
                update(id[edges[u].u],v,1,idx,1);
            } else{
                //N
                scanf("%d%d",&u,&v);
                parUpdate(u,v);
            }
        }
    }
}