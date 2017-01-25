//
// Created by Henry on 16/12/16.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define lowbit(x) (x&-x)

using namespace std;

typedef long long LL;

const int MAXN =  200000 + 5;
const int MAXE = MAXN;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL k,a[MAXN],b[MAXN],ans;
int n,cnt,In[MAXN];

struct edge{
    int v,next;
}G[MAXN];

int head[MAXN];
int cur;

LL tr[MAXN];

void add(int pos,int val){
    while (pos < cnt){
        tr[pos] += val;
        pos += lowbit(pos);
    }
}

LL query(int pos){
    LL res = 0;
    while (pos){
        res += tr[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(In,0, sizeof(In));
    cur = ans = 0;
}

void dfs(int u){
    int x = upper_bound(b,b+cnt,k/a[u]) - b;
    int pos = lower_bound(b,b+cnt,a[u]) - b + 1;

    ans += query(x);
    add(pos,1);
    for (int i = head[u]; ~i ; i = G[i].next) {
        dfs(G[i].v);
    }
    add(pos,-1);

}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();
        scanf("%d%lld",&n,&k);

        int scur = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%lld",&a[i]);

            b[scur++] = a[i];
            if (a[i] == 0) b[scur++] = INF;
            else b[scur++] = k/a[i];
        }

        sort(b,b+scur);
        cnt = unique(b,b+scur) - b;

        for (int i = 1; i < n; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;

            addedge_(u,v);
            In[v]++;
        }

        for (int i = 0; i < n; ++i) {
            if (!In[i]) dfs(i);
        }

        printf("%lld\n",ans);

    }
}
