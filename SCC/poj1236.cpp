//
// Created by Henry on 17/2/27.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 100 + 10;
const int MAXM = MAXN * MAXN;

//Star

struct node{
    int x,y;
}Nodes[MAXM];

struct edge{
    int v,next;
}G[MAXM];

int head[MAXN];
int cur,In[MAXN],Out[MAXN];

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next= head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(In,0, sizeof(In));
    memset(Out,0, sizeof(Out));

    cur = 0;
}

//Tarjan

int LOW[MAXN],DFN[MAXN],s[MAXN],Belong[MAXN];
bool instack[MAXN];

int scc,sidx,top;

void TDFS(int u){
    DFN[u] = LOW[u] = ++sidx;
    s[top++] = u;
    instack[u] = true;

    int v;
    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            TDFS(v);
            LOW[u] = min(LOW[v],LOW[u]);
        } else if(instack[v]){
            LOW[u] = min(DFN[v],LOW[u]);
        }
    }

    if (LOW[u] == DFN[u]){
        scc++;
        do{
            v = s[--top];
            instack[v] = false;
            Belong[v] = scc;
        } while (u != v);
    }
}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));

    scc = sidx = top = 0;

    for (int i = 1; i <= n; ++i) {
        if (DFN[i]) continue;
        TDFS(i);
    }
}

//Match
//int used[MAXN],match[MAXN];
//
//bool MDFS(int u){
//    used[u] = true;
//    for (int i = head[u]; ~i  ; i = G[i].next) {
//        int v = G[i].v,w = match[v];
//
//        if (w < 0 || !used[w] && MDFS(w)){
//            match[v] = u;
//            return true;
//        }
//    }
//    return false;
//}
//
//int Match(int l,int r){
//    memset(match,-1, sizeof(match));
//
//    int res = 0;
//    for (int i = l; i <= r; ++i) {
//        if (~match[i]) continue;
//        memset(used,0, sizeof(used));
//        if (MDFS(i)) res++;
//}
//
//return res;
//}
//main

int main(){
    int n;
    while (~scanf("%d",&n)){
        init();

        int ts1,ts2,cnt;
        ts1 = ts2 = cnt = 0;
        int tmp;
        for (int i = 1; i <= n; ++i) {
            while (scanf("%d",&tmp) && tmp) {
                Nodes[cnt].x = i;
                Nodes[cnt].y = tmp;
                addedge_(Nodes[cnt].x,Nodes[cnt].y);
                cnt++;
            }
        }

        Tarjan(n);

        for (int i = 0; i < cnt ; ++i) {
            int u,v;
            u = Belong[Nodes[i].x];
            v = Belong[Nodes[i].y];
            if (u == v) continue;
            In[v]++;
            Out[u]++;
        }


        int cntIn = 0,cntOut = 0;
        for (int i = 1; i <= scc; ++i) {
            if (!In[i]) cntIn++;
            if (!Out[i]) cntOut++;
        }

        ts1 = cntIn;
        ts2 = max(cntIn,cntOut);

        printf(scc == 1 ? "1\n0\n" : "%d\n%d\n",ts1,ts2);
    }
}