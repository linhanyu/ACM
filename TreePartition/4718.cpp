////
//// Created by Henry on 17/2/3.
////



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
const int INF = -0x3f3f3f3f;

int lsum[MAXN<<2],rsum[MAXN<<2],msum[MAXN<<2],siz[MAXN],id[MAXN],dep[MAXN],top[MAXN],son[MAXN],fa[MAXN],head[MAXN],val[MAXN],A[MAXN];
int cur,idx;
struct edge{
    int v,next;
}G[MAXN << 1];

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
    siz[0] = cur = idx = 0;
}

void Cdfs(int u,int f,int d){
    dep[u] = d;
    son[u] = 0;
    fa[u] = f;
    siz[u] = 1;

    for (int i = head[u]; ~i ; i = G[i].next) {
        if (f == G[i].v) continue;

        Cdfs(G[i].v,u,d+1);
        siz[u] += siz[G[i].v];
        if (siz[son[u]] < siz[G[i].v]) son[u] = G[i].v;
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

void pushUp(int l,int r,int rt){
    lsum[rt] = lsum[L];
    rsum[rt] = rsum[R];


    msum[rt] = max(msum[L],msum[R]);
    int mid = MID;
    if(val[mid] < val[mid+1]) {
        int len = r-l+1;
        if (lsum[rt] == len - (len>>1))
            lsum[rt] += lsum[R];
        if (rsum[rt] == (len>>1))
            rsum[rt] += rsum[L];

        msum[rt] = max(rsum[L] + lsum[R],msum[rt]);
    }
}



void build(int l,int r,int rt){
    if (l == r){
        lsum[rt] = rsum[rt] = msum[rt] = 1;
        return;
    }

    int mid = MID;
    build(lson);
    build(rson);
    pushUp(l,r,rt);
}


int query(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return msum[rt];
    }

    int mid = MID;

    if (mid < LB)
        return query(LB,RB,rson);
    else if (mid >= RB)
        return query(LB,RB,lson);
    else{
        int ans = max(query(LB,RB,lson),query(LB,RB,rson));
        int rs = min(lsum[R],RB - mid);
        int ls = min(rsum[L],mid - LB + 1);
        if (val[mid] < val[mid+1])
            return max(ans,ls + rs);
        return ans;
    }
}

int lsumQuery(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return lsum[rt];
    }

    int mid = MID;
    if (mid < LB) return lsumQuery(LB,RB,rson);
    else if (mid >= RB) return lsumQuery(LB,RB,lson);
    else{
        int ans = lsumQuery(LB,RB,lson);
        if (A[mid] < A[mid+1] && ans == mid - LB + 1) ans += min(RB - mid,lsum[R]);
        return ans;
    }
}

int rsumQuery(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return rsum[rt];
    }

    int mid = MID;
    if (mid < LB) return rsumQuery(LB,RB,rson);
    else if (mid >= RB) return rsumQuery(LB,RB,lson);
    else{
        int ans = rsumQuery(LB,RB,rson);
        if (A[mid] < A[mid+1] && ans == RB - mid) ans += min(mid - LB + 1,rsum[L]);
        return ans;
    }
}

int parQuery(int x,int y){
    int tp1 = top[x],tp2 = top[y],u=x,v=y;

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

    if (dep[x] < dep[y]) swap(x,y);
    ans = max(ans,query(id[y],id[x],1,idx,1));


}

void debug(){
    for (int i = 1; i <= 9; ++i) {
        val[i] = i;
    }

    build(1,9,1);

    printf("%d\n",query(5,9,1,9,1));
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t  ; ++cases) {
        printf("Case #%d:\n",cases);

        int n;
        for (int i = 1; i <= n; ++i) scanf("%d",&A[i]);

        for (int i = 2; i <= n ; ++i) {
            int v;
            scanf("%d",&v);
            addedge(i,v);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);

        for (int i = 1; i <= n ; ++i) {
            val[id[i]] = A[i];
        }

        build(1,idx,1);
        int q;
        scanf("%d",&q);
        while (q--){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",parQuery(u,v));
        }
    }
}