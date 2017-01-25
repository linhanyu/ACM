//
// Created by Henry on 16/10/2.
//

#include <cstdio>
#include <vector>
#include <memory>

using namespace std;

const int MAXV = 500 + 10;

int V;
vector<int > G[MAXV];
int match[MAXV];
bool used[MAXV];

void addAdge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        int u = G[v][i],w=match[u];
        if(w<0 || !used[w] && dfs(w)){
            match[u] = v;
            match[v] = u;
            return true;
        }
    }

    return false;
}

int bipartiteMatch(){
    int res=0;
    memset(match,-1, sizeof(match));
    for (int v = 1; v <= V; ++v) {
        if(match[v] < 0){
            memset(used,0, sizeof(used));
            if (dfs(v)){
                res++;
            }
        }
    }

    return res;
}

void init(){
    for (int i = 1; i < MAXV; ++i) {
        G[i].clear();
    }
}

int main(){
    int cases,n,p,m,tmp;
    scanf("%d",&cases);
    while (cases--){
        init();
        scanf("%d %d",&p,&n);
        V = p;
        for (int i = 1; i <= p; ++i) {
            scanf("%d",&m);
            while (m--){
                scanf("%d",&tmp);
                addAdge(i,tmp+p);
            }
        }

        if (bipartiteMatch() == p) puts("YES");
        else puts("NO");
    }
}