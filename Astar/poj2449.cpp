//
// Created by Henry on 16/10/26.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXV = 1000 + 10;
const int MAXE = 200000 + 10;
const int INF = 0x3f3f3f3f;

struct Anode{
    int n,g,h;

    bool operator<(const Anode & a) const{
        if (g + h == a.g + a.h){
            return g > a.g;
        }
        return g + h > a.g + a.h;
    }
};

struct edge{
    int v,cost,next;
}G[MAXE];


int n,m,src,dst,k,cur;
int head[MAXV],revhead[MAXV],dist[MAXV];

void addedge_(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addedgerev_(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = revhead[u];
    revhead[u] = cur++;
}

void addedge(int u,int v,int cost){
    addedge_(u,v,cost);
    addedgerev_(v,u,cost);
}

bool Relaxable(int u,edge & e,int & relax){
    relax = dist[u] + e.cost;
    return relax < dist[e.v];
}

bool revspfa(int s,int e){
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

        for (int i = revhead[s]; ~i ; i = G[i].next) {
            int relax;
            edge & e = G[i];

            if (Relaxable(s,e,relax)){
                dist[e.v] = relax;

                if (Outqueue[e.v]){
                    Q.push(e.v);
                    Outqueue[e.v] = false;
                }
            }
        }

    }

    return dist[e] < INF;
}

int Astar(int src,int dst,int k){
    static int color[MAXV];

    if (src == dst) k++;
    memset(color,0, sizeof(color));

    Anode a;
    priority_queue<Anode > Q;

    a.n = src;
    a.g = 0;
    a.h = dist[src];

    Q.push(a);

    while(!Q.empty()){
        Anode u = Q.top();
        Q.pop();

        if (++color[u.n] > k) continue;

        if (color[dst] == k) return u.g;

        for (int i = head[u.n]; ~i ; i = G[i].next) {
            Anode v;
            v.n = G[i].v;
            v.g = u.g + G[i].cost;
            v.h = dist[G[i].v];

            Q.push(v);
        }

    }

    return 0;


}

void init(){
    memset(head,-1, sizeof(head));
    memset(revhead,-1, sizeof(revhead));
    cur = 0;
}

int main(){
    while (~scanf("%d %d",&n,&m)){
        init();

        while (m--){
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            addedge(u,v,cost);
        }

        scanf("%d%d%d",&src,&dst,&k);
        int ans;
        printf("%d\n",revspfa(dst,src) ? ((ans = Astar(src,dst,k)) ? ans : -1) : -1);
    }
}