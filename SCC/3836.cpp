//
// Created by Henry on 17/2/28.
//

#include<cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAXN = 20000 + 10;
const int MAXM = 50000 + 10;

struct node{
    int x,y;
}Nodes[MAXM];

bool ZeroIn[MAXN],ZeroOut[MAXN];

//Star
struct edge{
    int v,next;
}G[MAXM];

int head[MAXN];
int cur;

void addedge_(int u,int v){
    Nodes[cur].x = u;
    Nodes[cur].y = v;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(ZeroIn,1, sizeof(ZeroIn));
    memset(ZeroOut,1, sizeof(ZeroOut));

    cur = 0;
}

//Tarjan

int DFN[MAXN],LOW[MAXN],s[MAXN],Belong[MAXN];
int sidx,top,scc;
bool instack[MAXN];

void TDFS(int u){
    DFN[u] = LOW[u] = ++sidx;
    instack[u] = true;
    s[top++] = u;

    int v;
    for (int i = head[u]; ~i  ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            TDFS(v);
            LOW[u] = min(LOW[u],LOW[v]);
        } else if (instack[v]){
            LOW[u] = min(LOW[u],DFN[v]);
        }
    }

    if (LOW[u] == DFN[u]){
        scc++;
        do{
            v = s[--top];
            instack[v] = false;
            Belong[v] = scc;
        }while (v!=u);
    }
}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));

    sidx = top = scc = 0;
    for (int i = 1; i <= n; ++i) {
        if (!DFN[i]) TDFS(i);
    }
}
//main
int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i = 0; i < m; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge_(u,v);
        }

        Tarjan(n);
        if(scc <= 1){
            puts("0");
            continue;
        }
        for (int i = 0; i < cur; ++i) {
            if (Belong[Nodes[i].x] == Belong[Nodes[i].y]) continue;
            ZeroIn[Belong[Nodes[i].y]] = false;
            ZeroOut[Belong[Nodes[i].x]] = false;
        }

        int cntIn,cntOut;
        cntIn = cntOut = 0;
        for (int i = 1; i <= scc ; ++i) {
            if (ZeroIn[i]) cntIn++;
            if (ZeroOut[i]) cntOut++;

        }

        printf("%d\n",max(cntIn,cntOut));
    }
}