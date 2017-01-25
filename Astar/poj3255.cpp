//
// Created by Henry on 16/10/26.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

const int MAXE = 400000 + 10;
const int MAXV = 5000 + 10;
//
struct Anode{
    int n,g,h;
    //n,本节点
    //g,开始到本node的实际代价
    //h,node到终点的估计代价
    bool operator<(const Anode & a) const {
        if(g + h == a.g + a.h){
            return g > a.g;
        }
        return g + h > a.g + a.h;
    }
};

struct edge{
    int next,v,cost;
}G[MAXE];

int head[MAXV],dist[MAXV];
int cur,n,r;

bool Relaxable(int u,edge & e,int & relax){
    relax = dist[u] + e.cost;
    return relax < dist[e.v];
}

void spfa(int s){
    static bool Outqueue[MAXV];

    memset(Outqueue,1, sizeof(Outqueue));
    memset(dist,0x3f, sizeof(dist));
    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        Outqueue[s] = true;

        for (int i = head[s]; ~i; i = G[i].next) {
            int relax;
            if (Relaxable(s,G[i],relax)){
                dist[G[i].v] = relax;

                if (Outqueue[G[i].v]){
                    Outqueue[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }
}

void add_edge(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addEdge(int u,int v,int cost){
    add_edge(u,v,cost);
    add_edge(v,u,cost);
}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

int Astar(int src,int dst){
    int cnt = 0;
    priority_queue<Anode> Q;
    Anode u;

    u.n = src;
    u.g = 0;
    u.h = dist[src];
    Q.push(u);

    while (!Q.empty()){
        u = Q.top();
        Q.pop();

        if (u.n == dst){
            if (++cnt == 2){
                return u.g;
            }
        }

        for (int i = head[u.n]; ~i ; i = G[i].next) {
            Anode v;

            v.n = G[i].v;
            v.g = u.g + G[i].cost;
            v.h = dist[v.n];
            Q.push(v);


        }
    }

    return 0;
}

int main(){
    while(~scanf("%d %d",&n,&r)){
        init();

        for (int i = 0; i < r; ++i) {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            addEdge(u,v,cost);
        }

        spfa(n);
//        Astar(1,n);
        printf("%d\n",Astar(1,n));
    }
}