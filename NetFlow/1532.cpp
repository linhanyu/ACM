//
// Created by Henry on 16/9/25.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>

using namespace std;

const int MAXN= 201;
const int INF = 0x7FFFFFFF;
int G[MAXN][MAXN];
int level[MAXN];
int n,m;

void addEdge(int u,int v,int cap){
    G[u][v] += cap;
}

void BFS(int begin){
    memset(level,-1, sizeof(level));

    queue<int > Q;
    Q.push(begin);
    level[begin] = 0;

    while(!Q.empty()){
        int source = Q.front();
        Q.pop();

        for (int i = 1; i <= m ; ++i) {
            if (level[i] < 0 && G[source][i]){
                level[i] = level[source] + 1;
                Q.push(i);
            }
        }
    }

}

int dfs(int u,int t,int f){
    if (u == t) return f;

    for (int i = 1; i <= m; ++i) {
        if(G[u][i] > 0 && level[u] < level[i]){
            int d = dfs(i,t,min(f,G[u][i]));

            if (d>0){
                G[u][i] -= d;
                G[i][u] += d;
                return d;

            }

        }
    }

    return 0;
}

int maxFlow(int s,int t){
    int flow = 0;
    for(;;){
        BFS(s);
        if (level[t] < 0) return flow;

        int f;
        while ((f = dfs(s,t,INF)) > 0 ){
            flow += f;
        }


    }
}

void init(){
    memset(G,0, sizeof(G));
}

int main(){
    while (cin>>n>>m){
        init();
        for (int i = 0; i < n; ++i) {
            int u,v,cap;
            cin>>u>>v>>cap;
            G[u][v] += cap;
        }

        printf("%d\n",maxFlow(1,m));
    }
}