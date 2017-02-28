//
// Created by Henry on 17/2/26.
//
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;


const int MAXN = 2000 + 10;

struct edge{
    int v, next;
}G[MAXN*MAXN];

char str[MAXN];
//
int head[MAXN];
int cur;
//
bool instack[MAXN];
bool flg;
int s[MAXN],Low[MAXN],Dfn[MAXN];
int sidx,top,scc;

void addedge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

void TarjanDfs(int u){


    Low[u] = Dfn[u] = ++sidx;
    s[top++] = u;
    instack[u] = true;

    for (int i = head[u]; ~i ; i = G[i].next) {

        if (!Dfn[G[i].v]){
            TarjanDfs(G[i].v);
            if (flg) return;
            Low[u] = min(Low[u],Low[G[i].v]);
        } else if (instack[G[i].v] && Low[u] > Dfn[G[i].v]){
            Low[u] = Dfn[G[i].v];
        }
    }

    if (Low[u] == Dfn[u]){
        scc++;
        int v,num = 0;

        do{
            v = s[--top];
            instack[v] = false;
            num++;
        }while(v!=u);

        if (num >= 3) flg = true;
    }
}

bool Tarjan(int n){
    memset(Dfn,0, sizeof(Dfn));
    memset(instack,0, sizeof(instack));

    sidx = top = scc = 0;
    flg = false;

    for (int i = 0; i < n; ++i) {
        if (Dfn[i]) continue;
        TarjanDfs(i);
        if (flg) return true;
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        init();

        printf("Case #%d: ",cases);
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%s",str);
            for (int j = 0; j < n; ++j) {
                if (str[j] == '1'){
                    addedge_(i,j);
                }
            }
        }

        puts(Tarjan(n) ? "Yes" : "No");

    }
}
