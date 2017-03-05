//
// Created by Henry on 17/3/1.
//


#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <functional>
#include <map>
using namespace std;

const int MAXN = 2000 + 10;
const int MAXM = MAXN*MAXN;


//star

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

//Tarjan;

int addblock[MAXN],s[MAXN],LOW[MAXN],DFN[MAXN];
bool cut[MAXN];
int sidx;

void TDFS(int u,int pre){
    LOW[u] = DFN[u] = ++sidx;
    int v,son = 0;

    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            son++;
            TDFS(v,u);
            LOW[u] = min(LOW[u],LOW[v]);

            if (u != pre && LOW[v] >= DFN[u]){
                addblock[u]++;
                cut[u] = true;
            }
        } else{
            LOW[u] = min(LOW[u],DFN[v]);
        }
    }

    if (u == pre) {
        if (son > 1)cut[u] = true;
        addblock[u] = son - 1;
    }
}

void Tarjan(int n){
    memset(addblock,0, sizeof(addblock));
    memset(DFN,0, sizeof(DFN));
    memset(cut,0, sizeof(cut));

    sidx = 0;

    for (int i = 1; i <= n; ++i) {
        if(!DFN[i]) TDFS(i,i);
    }
}

int main(){
    int cases = 1,cnt = 1,maxnode;
    int u,v;
    while (~scanf("%d",&u)){
        init();
        if (!u) break;
        maxnode = 0;
        scanf("%d",&v);
        addedge(u,v);
        maxnode = max(u,max(v,maxnode));

        while (~scanf("%d",&u) && u){
            scanf("%d",&v);
            addedge(u,v);
            maxnode = max(u,max(v,maxnode));
        }

        Tarjan(maxnode);
        printf("Network #%d\n",cases++);
        bool flg = true;
        for (int i = 1; i <= maxnode ; ++i) {
            if (cut[i]){
                printf("  SPF node %d leaves %d subnets\n",i,addblock[i] + 1);
                flg = false;
            }
        }
        puts(flg ? "  No SPF nodes\n":"");
    }
}