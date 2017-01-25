//
// Created by Henry on 16/9/29.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>
using namespace std;

const int MAXN = 1000 + 10;
const int src = 1001;
const int dst = 1002;
const int INF = 0x7FFFFFFF;
const int OFFSET = 500;

struct Edge{
    int to,cap,rev;

    Edge(){}
    Edge(int t,int c,int r):to(t),cap(c),rev(r){}

};

vector<Edge> G[MAXN];
int level[MAXN];
int iter[MAXN];

void addEdge(int from,int to,int cap){
    G[from].push_back(Edge(to,cap,G[to].size()));
    G[to].push_back(Edge(from,0,G[from].size() - 1));
}

void BFS(int begin){
    memset(level,-1, sizeof(level));

    queue<int > Q;

    Q.push(begin);
    level[begin] = 0;

    while(!Q.empty()){
        int source = Q.front();
        Q.pop();

        for (int i = 0; i < G[source].size(); ++i) {
            Edge & e = G[source][i];

            if (e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[source] + 1;
                Q.push(e.to);
            }
        }

    }


}

int dfs(int u,int t,int f){
    if (u == t) return f;

    for (int & i = iter[u]; i < G[u].size(); ++i) {
        Edge & e = G[u][i];

        if (e.cap > 0 && level[u] < level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));

            if (d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

int maxFlow(int s,int t){
    int flow=0;
    for (;;) {
        BFS(s);
        if (level[t] < 0) return flow;

        memset(iter,0, sizeof(iter));
        int f;
        while ((f = dfs(s,t,INF)) > 0){
            flow += f;
        }
    }
}

void init(){
    for (int i = 0; i < MAXN; ++i) {
        G[i].clear();
    }
}

int main(){
    int cases,n,m,minDay,maxDay,sum;

    scanf("%d",&cases);
    for (int cas = 1; cas <= cases; ++cas) {
        init();
        scanf("%d %d",&n,&m);

        minDay = INF;
        maxDay = 0;
        sum = 0;

        for (int i = 0; i < n; ++i) {
            int p,s,e;
            scanf("%d %d %d",&p,&s,&e);
            s += OFFSET;
            e += OFFSET;
            sum += p;
            minDay = min(minDay,s);
            maxDay = max(maxDay,e);


            addEdge(src,i,p);
            for (int j = s; j <= e ; ++j) {
                addEdge(i,j,1);
            }

        }

        for (int i = minDay; i <= maxDay ; ++i) {
            addEdge(i,dst,m);
        }

        if (maxFlow(src,dst) == sum){
            printf("Case %d: Yes\n",cas);
        } else{
            printf("Case %d: No\n",cas);
        }
        puts("");

    }
}