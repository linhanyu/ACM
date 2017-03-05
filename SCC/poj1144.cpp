//
// Created by Henry on 17/2/28.
//

#include<cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 20000 + 10;
const int MAXM = 50000 + 10;


//Star
struct edge{
    int v,next;
}G[MAXM];

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

//Tarjan

int DFN[MAXN],LOW[MAXN];
int sidx;
bool cut[MAXN];

void TDFS(int u,int pre){
    LOW[u] = DFN[u] = ++sidx;
    int son = 0;
    int v;

    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;
        if (v == pre) continue;
        if (!DFN[v]){
            son++;
            TDFS(v,u);
            LOW[u] = min(LOW[v],LOW[u]);
            if (u != pre && LOW[v] >= DFN[u]){
                cut[u] = true;
            }
        } else{
            LOW[u] = min(DFN[v],LOW[u]);
        }
    }

    if (u == pre && son > 1) cut[u] = true;

}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(cut,0, sizeof(cut));

    sidx = 0;

    for (int i = 1; i <= n ; ++i) {
        if (!DFN[i]) TDFS(i,i);
    }
}

//main
int main(){

    //freopen("input.txt","r",stdin);
    int n;
    while(~scanf("%d",&n) && n){
        init();

        int u,v;
        while(scanf("%d",&u) && u){
            while(getchar()!='\n'){
                scanf("%d",&v);
                addedge(u,v);
            }
        }
        Tarjan(n);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(cut[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}