//
// Created by Henry on 17/3/6.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>

#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;

const int MAXN = 2*1e5 + 10;
const int MAXM = 2*1e6 + 10;

struct Node{
    int x,y;
}nodes[MAXM];


//star

map<int,bool> dpl[MAXN];
int head[MAXN];
int cur,n;


struct edge{
    int v, next;
}G[MAXM];


void addedge_(int u,int v){
    if(dpl[u][v])return;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
    dpl[u][v] = true;
}

void addedge(int u,int v){

    addedge_(u,v);
    addedge_(v,u);
}

void initStar(){
    cur = 0;
    memset(head,-1, sizeof(head));
    for (int i = 1; i < MAXN; ++i) dpl[i].clear();
}

//Tarjan

int LOW[MAXN],DFN[MAXN],s[MAXN],Belong[MAXN];
int sidx,top,scc,bridge;
bool instack[MAXN];

void TDFS(int u,int pre){
    LOW[u] = DFN[u] = ++sidx;
    s[top++] = u;
    instack[u] = true;

    int v;
    for (int i = head[u]; ~i  ; i = G[i].next) {
        v = G[i].v;
        if (v == pre) continue;

        if (!DFN[v]){
            TDFS(v,u);
            LOW[u] = min(LOW[v],LOW[u]);

            if (LOW[v] > DFN[u]){
                bridge++;
            }
        } else if (instack[v]){
            LOW[u] = min(LOW[u],DFN[v]);
        }
    }

    if (LOW[u] == DFN[u]){
        scc++;
        do{
            v = s[--top];
            Belong[v] = scc;
            instack[v] = false;
        }while (u != v);
    }
}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));

    bridge = sidx = scc = top = 0;

    for (int i = 1; i <= n ; ++i) {
        if (!DFN[i]) TDFS(i,i);
    }
}
//diameter
int nex[MAXN];

int diadfs(int u,int pre){
    int len = -1;
    nex[u] = -1;
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (pre == G[i].v) continue;

        int tmplen = diadfs(G[i].v,u);
        if (tmplen > len){
            nex[u] = G[i].v;
            len = tmplen;
        }
    }

    return len + 1;
}
//main

int main(){
    int m;

    while (~scanf("%d%d",&n,&m) && (n||m)){
        initStar();
        for (int i = 0; i < m; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            nodes[i].x = u;
            nodes[i].y = v;

        }

        Tarjan(n);
        initStar();

        for (int i = 0; i < m; ++i) {
            int u = Belong[nodes[i].x];
            int v = Belong[nodes[i].y];

            if (u == v) continue;
            addedge(u,v);
        }

        int st = 1;
        diadfs(st,st);
        while (~nex[st]) st = nex[st];
        printf("%d\n",bridge  -  diadfs(st,st));

    }
}