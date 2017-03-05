//
// Created by Henry on 17/3/4.
//
#include <set>
#include<cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

const int MAXN = 5000 + 10;
const int MAXM = 30000 + 10;
//UFSet

int UFSet[MAXN];

int Find(int rt) { return UFSet[rt] < 0 ? rt : Find(UFSet[rt]);}

void Merge(int rt1,int rt2){
    rt1 = Find(rt1);
    rt2 = Find(rt2);

    if (rt1 != rt2) UFSet[rt1] = rt2;
}

void initUFSet(){
    memset(UFSet,-1, sizeof(UFSet));
}

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

void initStar(){
    memset(head,-1, sizeof(head));

    cur = 0;
}

//Tarjan

struct Bedge{
    int u,v;
}s[MAXN];

set<int> Contain[MAXN];

int DFN[MAXN],LOW[MAXN],edges[MAXN];
int sidx,top,scc;
bool instack[MAXN];



void TDFS(int u ,int pre){
    DFN[u] = LOW[u] = ++sidx;
    instack[u] = true;

    int v;

    for (int i = head[u];~i; i = G[i].next) {
        v = G[i].v;
        if (v == pre) continue;

        if (!DFN[v]){
            s[top].u = u;
            s[top].v = v;
            top++;

            TDFS(v,u);
            LOW[u] = min(LOW[u],LOW[v]);
            if (LOW[v] >= DFN[u]){
                scc++;
                Contain[scc].clear();
                Bedge tmpedge;
                do{
                    tmpedge = s[--top];
                    Contain[scc].insert(tmpedge.u);
                    Contain[scc].insert(tmpedge.v);
                }while (tmpedge.u != u);
            }

        } else if (instack[v]){
            LOW[u] = min(DFN[v],LOW[u]);
        }
    }


}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));
    memset(edges,0, sizeof(edge));
    sidx = top = scc = 0;


    for (int i = 0; i < n; ++i) {
        if (!DFN[i]) TDFS(i,i);
    }
}
//main

int main(){
    int n,m,q,cases = 0;
    while (~scanf("%d%d%d",&n,&m,&q) && (n||m||q)){
        initStar();
        initUFSet();

        printf("Case %d:\n",++cases);
        int u,v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            Merge(u,v);
        }

        Tarjan(n);

        while (q--){
            scanf("%d%d",&u,&v);
            if (Find(u) == Find(v)){
                bool flg = false;
                for (int i = 1; i <= scc; ++i) {
                    if (Contain[i].size() > 2 && Contain[i].count(u) && Contain[i].count(v)){
                        flg = true;
                        break;
                    }
                }

                puts(flg ? "two or more" : "one");
            } else{
                puts("zero");
            }
        }
    }
}