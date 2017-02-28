//
// Created by Henry on 17/2/26.
//


#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <map>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;

//star

int head[MAXN];
int cur;

struct edge{
    int v, next;
}G[MAXM];


void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

//Tarjan

int LOW[MAXN],DFN[MAXN],s[MAXN];
int top,sidx,scc;
bool flg,instack[MAXN];

void TarjanDfs(int u){
    LOW[u] = DFN[u] = ++sidx;
    s[top++] = u;
    instack[u] = true;

    int v;
    for (int i = head[u]; ~i  ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            TarjanDfs(v);
            if (!flg) return;
            LOW[u] = min(LOW[u],LOW[v]);
        } else if (instack[v]){
            LOW[u] = min(LOW[u],DFN[v]);
        }
    }

    if (LOW[u] == DFN[u]){
        scc++;
        flg = scc <= 1;
        do{
            v = s[--top];
            instack[v] = false;
        }while (v != u);
    }
}

bool Tarjan(int n){
    memset(instack,0, sizeof(instack));
    memset(DFN,0, sizeof(DFN));

    sidx = top = scc = 0;
    flg = true;
    for (int i = 1; i <= n; ++i) {
        if (DFN[i])continue;
        TarjanDfs(i);
    }
    return flg;
}

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m) && (m || n)){
        init();

        while (m--){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge_(u,v);
        }

        puts(Tarjan(n) ? "Yes":"No");

    }
}