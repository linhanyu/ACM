//
// Created by Henry on 16/11/9.
//
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAXM = 1000 + 10;
const int MAXN = 100 + 10;

struct edge{
    int v, next;
}G[MAXM];

int s[MAXN],head[MAXN];
int cur,scur;

bool visV[MAXN],visE[MAXM],w[MAXN];

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;

}

void addedge(int u,int v){
    addedge_(u,v);
    addedge_(v,u);
}

int dfs(int u){
    visV[u] = true;
    int ret = 0;
    s[scur++] = u;

    for (int i = head[u]; ~i; i = G[i].next) {
        if (!visE[i]){
            visE[i] = visE[i^1] = true;
            int tt;

            if (!visV[G[i].v]){
                tt = dfs(G[i].v) + 1;
            } else{
                int q = s[--scur];
                while (q != G[i].v){
                    w[q] = true;
                    q = s[--scur];
                }

                ++scur;
                return 1;
            }

            ret ^= w[G[i].v] ? tt % 2 : tt ;

        }
    }

    return ret;
}

void init(){
    cur = scur = 0;
    memset(head,-1, sizeof(head));
    memset(visE, false, sizeof(visE));
    memset(visV, false, sizeof(visV));
    memset(w, false, sizeof(w));

}
int main(){
    int t;

    while (~scanf("%d",&t)){
        int ans = 0;

        while (t--){
            init();

            int m,k;
            scanf("%d %d",&m,&k);
            for (int i = 0; i < k; ++i) {
                int u,v;
                scanf("%d%d",&u,&v);
                addedge(u,v);
            }

            ans ^= dfs(1);
        }


        puts(ans ? "Sally" : "Harry");
    }
}


