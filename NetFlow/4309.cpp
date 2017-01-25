//
// Created by Henry on 16/9/27.
//

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 110;
const int INF = 0x7FFFFFFF;
const int src = 101;
const int dst = 102;

struct Edge{
    int to,cap,rev;
    Edge(){}
    Edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};

struct Brg{
    int u,v,cost;
    Brg(){}
    Brg(int u,int v,int cost):u(u),v(v),cost(cost){}
};

vector<Edge> BG[MAXN];
vector<Edge> G[MAXN];
vector<Brg> Bridge;

void addEdge(int from,int to,int cap){
    G[from].push_back(Edge(to,cap,G[to].size()));
    G[to].push_back(Edge(from,0,G[from].size() - 1));
}


int level[MAXN];

void BFS(int begin){
    queue<int> Q;
    memset(level,-1, sizeof(level));

    Q.push(begin);
    level[begin] = 0;

    while (!Q.empty()){
        int source = Q.front();
        Q.pop();

        for (int i = 0; i < BG[source].size(); ++i) {
            Edge & e = BG[source][i];

            if (e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[source] + 1;
                Q.push(e.to);
            }
        }

    }

}

int dfs(int u,int t,int f){
    if(u == t) return f;

    for (int i = 0; i < BG[u].size(); ++i) {
        Edge & e = BG[u][i];

        if (e.cap > 0 && level[u] < level[e.to]){
            int d = dfs(e.to,t,min(e.cap,f));

            if (d > 0){
                e.cap -= d;
                BG[e.to][e.rev].cap += d;
                return d;
            }
        }

    }

    return 0;

}

int maxFlow(int s,int t){
    int flow = 0;

    for (;;) {
        BFS(s);
        if (level[t] < 0) return flow;
        int f;
        while ((f = dfs(s,t,INF)) > 0){
            flow += f;
        }

    }
}

void initBG(){
    for (int i = 0; i < MAXN; ++i) {
        BG[i] = G[i];
    }
}
void init(){
    Bridge.clear();
    for (int i = 0; i < MAXN; ++i) {
        G[i].clear();
    }
}

int main(){
    int n,m;

    while(scanf("%d %d",&n,&m)!=EOF){
        int u,v,w,p;

        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&u);
            addEdge(src,i,u);
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d",&u,&v,&w,&p);

            if (p < 0){
                addEdge(u,dst,w);
                addEdge(u,v,INF);
            }else if(p == 0){
                addEdge(u,v,INF);
            } else{
                addEdge(u,v,1);

                Bridge.push_back(Brg(u,G[u].size()-1,w));
            }

        }


        int Mf,Mc;
        Mf = 0;
        Mc = INF;
        int end = 1<<Bridge.size();
        for (int i = 0; i < end; ++i) {
            //状压
            int c=0, f=0;
            initBG();

            for (int j = 0; j < Bridge.size(); j++) {
                if((1<<j) & i){
                    Brg & b = Bridge[j];
                    c += b.cost;
                    BG[b.u][b.v].cap = INF;
                }
            }

            f = maxFlow(src,dst);
            if (f >= Mf){
                if (f == Mf )
                {
                    if (c<Mc){
                        Mc = c;
                        continue;
                    }
                    continue;
                }
                Mf = f;
                Mc = c;
            }


        }


        if (Mf == 0) puts("Poor Heaven Empire");
        else printf("%d %d\n",Mf,Mc);

    }

}