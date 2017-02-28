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

struct node{
    int x,y;
}Nodes[MAXM];

//star

map<int,int > exist[MAXN];

int head[MAXN];
int cur;

struct edge{
    int v, next;
}G[MAXM];


void addedge_(int u,int v){
    if (exist[u][v])return;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
    exist[u][v] = 1;
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
    for (int i = 0; i < MAXN; ++i) exist[i].clear();
}

//Tarjan

int scc,top,sidx;
int s[MAXN],DFN[MAXN],LOW[MAXN],Belong[MAXN];
bool instack[MAXN];

void TDfs(int u){
    LOW[u] = DFN[u] = ++sidx;
    instack[u] = true;
    s[top++] = u;

    int v;

    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            TDfs(v);
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
        } while (v!=u);
    }
}


void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));

    scc = top = sidx = 0;

    for (int i = 1; i <= n; ++i) {
        if (DFN[i]) continue;
        TDfs(i);
    }
}

////match

int match[MAXN];
bool used[MAXN];

bool matchDfs(int u){
    used[u] = true;

    for (int i = head[u]; ~i ; i = G[i].next) {
        int v = G[i].v;
        int w = match[v];
        if (w < 0 || (!used[w] && matchDfs(w))){
            match[v] = u;
            return true;
        }
    }
    return false;
}

int maxiumMatch(int l,int r){
    memset(match,-1, sizeof(match));

    int res = 0;
    for (int i = l; i <= r; ++i) {
        if (~match[i]) continue;
        memset(used,0, sizeof(used));
        if (matchDfs(i)) res++;
    }

    return res;

}


//main

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();

        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d",&Nodes[i].x,&Nodes[i].y);
            addedge_(Nodes[i].x,Nodes[i].y);
        }
        Tarjan(n);

        init();

        for (int i = 0; i < m; ++i) {
            int u = Belong[Nodes[i].x];
            int v = Belong[Nodes[i].y];

            if (u == v) continue;

            addedge_(u,v);
        }


        printf("%d\n",scc - maxiumMatch(1,scc));

    }
}






