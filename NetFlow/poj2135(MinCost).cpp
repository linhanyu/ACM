//
// Created by Henry on 16/10/5.
//

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;


const int MAXV = 1000 + 10;
const int MAXE = 50000;
const int INF = 0x6FFFFFF;

struct edge{
    int v,cap,cost,next;
}G[MAXE];

int cur;
int head[MAXV];
int dist[MAXV];

void revSpfa(int s){
    bool outQ[MAXV];

    memset(outQ,1, sizeof(outQ));
    memset(dist,0x3f, sizeof(dist));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        outQ[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next) {
            if (G[i ^ 1].cap && dist[s] + G[i^1].cost < dist[G[i].v]){
                dist[G[i].v] = dist[s] + G[i].cost;
                if (outQ[G[i].v]){
                    outQ[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }

}


int MCISAP(int s,int t,int flow){
    revSpfa(t);

    int prev[MAXV],ecur[MAXV];
    int u,cost;

    prev[s] = u = s;
    cost = 0;
    memcpy(ecur,head, sizeof(ecur));

    while (flow>0 && dist[u] < INF){
        if (u == t){
            //aug
            int f = INF,neck = s;
            for (int i = s; i != t ; i = G[ecur[i]].v) {
                if (f > G[ecur[i]].cap){
                    f = G[ecur[i]].cap;
                    neck = i;
                }
            }

            flow -= f;
            cost += dist[s]*f;
            for (int i = s; i != t  ; i = G[ecur[i]].v) {
                G[ecur[i]].cap -= f;
                G[ecur[i]^1].cap += f;
            }

            u = neck;
        }

        int i;
        for (i = ecur[u]; ~i ; i = G[i].next) {
            if (G[i].cap &&  dist[u] == dist[G[i].v] + G[i].cost) break;
        }

        if (~i){
            //reset cur flag
            ecur[u] = i;
            prev[G[i].v] = u;
            u = G[i].v;
        } else{
            int mind = INF;
            for (int i = head[u]; ~i ; i = G[i].next) {
                if (G[i].cap && dist[G[i].v] + G[i].cost < mind){
                    mind = dist[G[i].v] + G[i].cost;
                    ecur[u] = i;
                }
            }

            dist[u] = mind;
            u = prev[u];
        }
    }

    return cost;
}

void add_Edge(int u,int v,int cap,int cost){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addEdge(int u,int v,int cap,int cost){
    add_Edge(u,v,cap,cost);
    add_Edge(v,u,0,-cost);
}




void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

//struct edge{
//    int v,cap,cost,rev;
//    edge(){}
//    edge(int t,int c,int cost,int rev):v(t),cap(c),cost(cost),rev(rev){}
//};
//
//
//int V;
//vecvr<edge> G[MAXV];
//int h[MAXV];
//int dist[MAXV];
//int prevv[MAXV],preve[MAXV];
//
//void addEdge(int u,int v,int cap,int cost){
//    G[u].push_back(edge(v,cap,cost,G[v].size()));
//    G[v].push_back(edge(u,0,-cost,G[u].size() - 1));
//}

//int MinCostFlow(int s,int t,int f){
//    int res=0;
//    fill(h,h+V,0);
//
//    while(f>0){
//        priority_queue<P,vecvr<P>,greater<P> > Q;
//        fill(dist,dist+V,INF);
//        dist[s] = 0;
//        Q.push(P(0,s));
//
//        while(!Q.empty()){
//            P p = Q.vp();
//            Q.pop();
//
//            int v = p.second;
//
//            if (dist[v] < p.first) continue;
//
//            for (int i = 0; i < G[v].size(); ++i) {
//                edge & e = G[v][i];
//                if (e.cap > 0 && dist[e.v] > dist[v] + e.cost + h[v] - h[e.v]){
//                    dist[e.v] = dist[v] + e.cost + h[v] - h[e.v];
//                    prevv[e.v] = v;
//                    preve[e.v] = i;
//                    Q.push(P(dist[e.v],e.v));
//                }
//            }
//        }
//
//        if (dist[t] == INF){
//            return -1;
//        }
//
//        for (int i = 0; i < V; ++i) {
//            h[i] += dist[i];
//        }
//
//        int d = f;
//        for (int v = t; v !=s ; v = prevv[v]) {
//            d = min(d,G[prevv[v]][preve[v]].cap);
//        }
//
//        f -= d;
//        res += d * h[t];
//        for (int v = t; v != s ; v = prevv[v]) {
//            edge & e = G[prevv[v]][preve[v]];
//            e.cap -= d;
//            G[e.v][e.rev].cap += d;
//        }
//
//
//
//    }
//    return res;
//}

int main(){
    int n,m;
    while (~scanf("%d %d",&n,&m)){
        init();

        for (int i = 0; i < m; ++i) {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            addEdge(u - 1,v - 1,1,c);
            addEdge(v - 1,u - 1,1,c);
        }
        printf("%d\n",MCISAP(0,n-1,2));
    }
}