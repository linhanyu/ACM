//
// Created by Henry on 17/1/15.
//

#include<cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

typedef long long LL;

const int MAXV = 100000 + 10;
const int MAXE = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


struct edge{
    int v,next;
}G[MAXE];

int head[MAXV],In[MAXV];
int cur;

LL ans[MAXV],a[MAXV],b[MAXV];

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(In,0, sizeof(In));
    memset(ans,0, sizeof(ans));
    cur = 0;
}



void topsort(queue<int > & Q ){
    while (!Q.empty()){
        int s = Q.front();
        Q.pop();

        for (int i = head[s]; ~i ; i = G[i].next) {
            ans[G[i].v] = (ans[G[i].v] + (b[s]+ans[s]) % MOD)%MOD;
            if (--In[G[i].v] == 0) Q.push(G[i].v);
        }

    }
}

int main(){
    int n,m;

    while (~scanf("%d%d",&n,&m)){
        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld",&a[i],&b[i]);
        }

        for (int i = 1; i <= m ; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge_(v,u);
            In[u]++;
        }

        queue<int > Q;
        for (int i = 1; i <= n; ++i) {
            if (In[i]) continue;
            Q.push(i);
        }

        topsort(Q);

        LL res = 0;
        for (int i = 1; i <= n ; ++i) {
            res = (res + (ans[i]*a[i])%MOD)%MOD;
        }

        printf("%lld\n",res);

    }
}