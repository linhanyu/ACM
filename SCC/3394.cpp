//
// Created by Henry on 17/3/6.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 2*1e5 + 10;

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

void addedge(int u,int v){
    addedge_(u,v);
    addedge_(v,u);
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

//Tarjan
struct Tedge{
    int u,v;
};

set<int > Belong[MAXN];
set<int > Contain[MAXN];
int LOW[MAXN],DFN[MAXN],ecounter[MAXN];
int scc,sidx,top,bridge;
bool instack[MAXN];
Tedge s[MAXN];

void TDFS(int u,int pre){
    DFN[u] = LOW[u] = ++sidx;
    instack[u] = true;

    int v;
    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;

        if (v == pre) continue;

        if (!DFN[v]){
            s[top].u = u;
            s[top].v = v;
            top++;

            TDFS(v,u);
            LOW[u] = min(LOW[u],LOW[v]);


            if (DFN[u] <= LOW[v]){

                if (LOW[v] > DFN[u]) bridge++;
                scc++;
                Contain[scc].clear();
                Tedge etmp;
                do{
                    etmp = s[--top];
                    Belong[etmp.u].insert(scc);
                    Belong[etmp.v].insert(scc);
                    Contain[scc].insert(etmp.u);
                    Contain[scc].insert(etmp.v);
                }while (etmp.u != u);
            }
        } else if(instack[u]){
            LOW[u] = min(LOW[u],DFN[v]);
        }
    }
}

void Tarjan(int n){
    memset(instack,0, sizeof(instack));
    memset(DFN,0, sizeof(DFN));

    bridge = scc = sidx = top = 0;


    for (int i = 0; i < n; ++i) {
        Belong[i].clear();
    }

    for (int i = 0; i < n; ++i) {
        if (!DFN[i]) TDFS(i,i);
    }
}


//main

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m) && (n||m)){
        init();
        for (int i = 0; i < m; ++i) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        Tarjan(n);

        int ans = 0;
        memset(ecounter,0, sizeof(ecounter));
        for (int i = 0; i < n; ++i) {
            for (int j = head[i]; ~j ; j = G[j].next) {
                int s = -1;
                set_intersection(Belong[i].begin(),Belong[i].end(),Belong[G[j].v].begin(),Belong[G[j].v].end(),&s);
                if (~s) ecounter[s]++;
            }
        }


        for (int i = 1; i <= scc; ++i) {
            if ((ecounter[i]>>1) > Contain[i].size()) ans += ecounter[i]>>1;
        }


        printf("%d %d\n",bridge,ans);
    }
}