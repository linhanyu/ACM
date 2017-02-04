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

const int MAXE = 30000 + 10;
const int MAXV = 30000 + 10;
const int INF = 0x3f3f3f3f;

struct edge{
    int v,next;
}G[MAXE<< 2];

int head[MAXV],fa[MAXV],son[MAXV],dep[MAXV],size[MAXV],id[MAXV],top[MAXV],sum[MAXV<<3],Max[MAXV<<3],val[MAXV];

int cur,idcur;

void Cdfs(int u,int f,int d){
    //color heavy node
    dep[u] = d;
    size[u] = 1;
    fa[u] = f;
    son[u] = 0;

    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == f) continue;

        Cdfs(G[i].v,u,d+1);
        size[u] += size[G[i].v];
        if (size[son[u]] < size[G[i].v]) son[u] = G[i].v;
    }
}

void Ldfs(int u,int tp){
    //link chain
    id[u] = ++idcur;
    top[u] = tp;
    if (son[u]) Ldfs(son[u],tp);

    for (int i = head[u]; ~i  ; i = G[i].next) {
        if (G[i].v == fa[u] || G[i].v == son[u]) continue;
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
    idcur = cur = 0;
}

void pushUp(int rt){
    Max[rt] = max(Max[L],Max[R]);
    sum[rt] = sum[L] + sum[R];
}

void build(int l,int r,int rt){
    if (l == r){
        Max[rt] = sum[rt] = val[l];
        return;
    }
    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int pos,int key,int l,int r,int rt){
    if (l == r){
        Max[rt] = sum[rt] = key;
        return;
    }

    int mid = MID;
    if (pos <= mid) update(pos,key,lson);
    if (pos >  mid) update(pos,key,rson);
    pushUp(rt);
}

int query(int op,int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        return op ? sum[rt] : Max[rt];
    }

    int mid = MID;
    int ans = op ? 0 : -INF;

    if (mid >= LB) {
        int tmp = query(op,LB,RB,lson);
        ans = op ? ans+tmp : max(ans,tmp);
    }

    if (mid < RB) {
        int tmp = query(op,LB,RB,rson);
        ans = op ? ans+tmp : max(ans,tmp);
    }

    return ans;
}

int main(){
    int n;
    while (~scanf("%d",&n)){
        init();
        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        Cdfs(1,0,1);
        Ldfs(1,1);
        for (int i = 1; i <= n ; ++i) scanf("%d",&val[id[i]]);

        build(1,idcur,1);
        int q,a,b;
        char str[10];
        scanf("%d",&q);
        while (q--){
            scanf("%s %d %d",str,&a,&b);
            if (str[0] == 'C') update(id[a],b,1,idcur,1);
            else{
                int ans;
                if (str[1] == 'S'){
                    int tp1 = top[a],tp2 = top[b];
                    ans = 0;

                    while (tp1 != tp2){
                        if(dep[tp1] < dep[tp2]){
                            swap(tp1,tp2);
                            swap(a,b);
                        }

                        ans += query(1,id[tp1],id[a],1,idcur,1);
                        a = fa[tp1];
                        tp1 = top[a];
                    }

                    if (dep[a] < dep[b])swap(a,b);
                    ans += query(1,id[b],id[a],1,idcur,1);
                } else{
                    int tp1 = top[a],tp2 = top[b];
                    ans = -INF;
                    while (tp1 != tp2){
                        if(dep[tp1] < dep[tp2]){
                            swap(tp1,tp2);
                            swap(a,b);
                        }

                        ans = max(ans,query(0,id[tp1],id[a],1,idcur,1));
                        a = fa[tp1];
                        tp1 = top[a];
                    }

                    if (dep[a] < dep[b]) swap(a,b);
                    ans = max(ans,query(0,id[b],id[a],1,idcur,1));
                }

                printf("%d\n", ans);

            }
        }
    }
}