//
// Created by Henry on 17/2/28.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <functional>
#include <map>
using namespace std;

const int MAXN = 4000 + 10;
const int MAXM = 200000*2 + 10;


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

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

//Tarjar

int s[MAXN],LOW[MAXN],DFN[MAXN],Belong[MAXN];
int sidx,scc,top;
bool instack[MAXN];

void TDFS(int u){
    LOW[u] = DFN[u] = ++sidx;
    s[top++] = u;
    instack[u] = true;

    int v;
    for (int i = head[u]; ~i ; i = G[i].next) {
        v = G[i].v;
        if (!DFN[v]){
            TDFS(v);
            LOW[u] = min(LOW[u],LOW[v]);
        } else if (instack[v]){
            LOW[u] = min(DFN[v],LOW[u]);
        }
    }

    if (LOW[u] == DFN[u]){
        scc++;
        do{
            v = s[--top];
            Belong[v] = scc;
            instack[v] = false;
        } while (v!=u);
    }
}

void Tarjan(int n){
    memset(DFN,0, sizeof(DFN));
    memset(instack,0, sizeof(instack));
    sidx = scc = top = 0;

    for (int i = 1; i <= n; ++i) {
        if (!DFN[i]) TDFS(i);
    }
}

//main

int main(){
    int n,k,v;
    while (~scanf("%d",&n)){
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&k);
            while (k--){
                scanf("%d",&v);
                addedge_(i,v + n);
            }
        }

        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&v);
            addedge_(v + n,i);
        }

        Tarjan(n<<1);

        for (int i = 1; i <= n; ++i) {
            top = 0;
            for (int j = head[i]; ~j; j = G[j].next) {
                if ( Belong[G[j].v] == Belong[i]){
                    s[top++] = G[j].v - n;
                }
            }
            printf("%d ",top);
            sort(s,s+top);
            for (k = 0; k < top; ++k) printf("%d%c",s[k],k == top-1 ? '\n':' ');
        }
    }
}


