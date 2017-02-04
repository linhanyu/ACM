#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXV = 1000 + 10;
const int MAXE = 1000;
const int INF = 0x3f3f3f3f;

struct edge{
    int next,v,cap,cost;
}G[MAXE];


int head[MAXV];
int dist[MAXV];
int cur;

void addedge_(int u,int v,int cap,int cost){
    G[cur].v = v;
    G[cur].cap = cap;
    G[cur].next = head[u];
    G[cur].cost = cost;
    head[u] = cur++;
}

void addedge(int u,int v,int cap,int cost){
    addedge_(u,v,cap,cost);
    addedge_(v,u,0,-cost);
}

void revSpfa(int s){
    int outQ[MAXV];

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
            if (G[i ^ 1].cap && dist[s] + G[i].cost < dist[G[i].v]){
                dist[G[i].v] = dist[s] + G[i].cost;
                if (outQ[G[i].v]){
                    outQ[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }

}


int MCISAP(int s,int t){
    revSpfa(t);

    int prev[MAXV],ecur[MAXV];
    int u,flow,cost;

    prev[s] = u = s;
    flow = cost = 0;
    memcpy(ecur,head, sizeof(ecur));

    while (dist[u] < INF){
        if (u == t){
            //aug
            int f = INF,neck = s;
            for (int i = t; i != s ; i = prev[i]) {
                if (f > G[ecur[i]].cap){
                    f = G[ecur[i]].cap;
                    neck = i;
                }
            }

            flow += f;
            cost += dist[s]*f;
            for (int i = t; i != s ; i = prev[i]) {
                G[ecur[i]].cap += f;
                G[ecur[i]^1].cap -= f;
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
                }
            }

            dist[u] = mind;
            u = prev[u];
        }
    }

    return cost;
}

//const int MAXE = 10000;
//const int MAXV = 10000;
//const int INF = 0x7FFFFFF;
//
//struct Edge{
//    int to;
//    int cap;
//    int next;
//} edge[MAXE];
//
//int n;
//
//int bufferCur;
//int head[MAXV];
//
//int level[MAXV];
//int appearV[MAXV];
//
//int pre[MAXV];
//int cur[MAXV];
//
//void addEdge(int from,int to,int cap){
//    edge[bufferCur].to = to;
//    edge[bufferCur].cap = cap;
//    edge[bufferCur].next = head[from];
//    head[from] = bufferCur++;
//
//    edge[bufferCur].to = from;
//    edge[bufferCur].cap = 0;
//    edge[bufferCur].next = head[to];
//    head[to] = bufferCur++;
//}
//
//void revBfs(int end){
//    memset(level,-1, sizeof(level));
//    memset(appearV,0, sizeof(appearV));
//
//    static queue<int > Q;
//
//    Q.push(end);
//    level[end] = 0;
//    appearV[0] = 1;
//
//    while(!Q.empty()){
//        int u = Q.front();
//        Q.pop();
//
//        for (int i = head[u]; i != -1 ; i = edge[i].next) {
//            int v = edge[i].to;
//            if (level[v]==-1){
//                level[v] = level[u] + 1;
//                appearV[level[v]]++;
//                Q.push(v);
//            }
//        }
//    }
//}
//
//int ISAP(int s,int t){
//
//    memcpy(cur,head, sizeof(head));
//
//    revBfs(t);
//
//    int u,int flow=0;
//    u = pre[s] = s;
//
//    while (level[t]< n){
//        if (u == t){
//            //增广完成
//            int f = INF,neck;
//            for (int i = s; i != t ; i = edge[cur[i]].to) {
//                if (f > edge[cur[i]].cap){
//                    f = edge[cur[i]].cap;
//                    neck = i;
//                }
//            }
//
//            for (int i = s; i != t ; i = edge[cur[i]].to) {
//                edge[cur[i]].cap -= f;
//                edge[cur[i] ^ 1].cap += f;
//            }
//
//            flow += f;
//            u = neck;
//        }
//
//        int i;
//        for (i = cur[u]; ~i; i=edge[i].next) {
//            if (level[edge[i].to] + 1 == level[u] && edge[i].cap > 0){
//                break;
//            }
//        }
//
//        if (~i){
//            cur[u] = i;
//            pre[edge[i].to] = u;
//            u = edge[i].to;
//        } else{
//            if (0 == (--appearV[level[u]])) break;
//
//            int mind = n;
//            for (int i = head[u]; ~i ; i = edge[i].next) {
//                if (edge[i].cap > 0 && mind > level[edge[i].to]){
//                    cur[u] = i;
//                    mind  = level[edge[i].to];
//                }
//            }
//
//            level[u] = mind + 1;
//            appearV[level[u]]++;
//            u = pre[u];
//        }
//
//    }
//
//}
//void init(){
//    memset(head,-1, sizeof(head));
//    bufferCur = 0;
//
//}


//const int MAXM = 10;
//const int OFFSET = 1<<MAXM;
//const int INF = 0x7FFFFFFF;
//const int src = OFFSET + MAXM + 1;
//const int dst = OFFSET + MAXM + 2;
//
//
//struct Edge{
//    int to,int cap,int rev;
//    Edge(){}
//    Edge(int t,int c,int r):to(t),cap(c),rev(r){}
//};
//
//vector<Edge> G[OFFSET + MAXM + 10];
//int level[OFFSET + MAXM + 10];
//
//
//void addNode(int from,int to,int cap){
//    G[from].push_back(Edge(to,cap,G[to].size()));
//    G[to].push_back(Edge(from,0,G[from].size() - 1));
//}
//
//void BFS_rev(int end){
//    memset(level,-1, sizeof(level));
//
//    queue<int> Q;
//
//    level[end] = 0;
//    Q.push(end);
//
//    while (!Q.empty()){
//        int u = Q.front();
//        Q.pop();
//
//        for (int i = 0; i < G[u].size(); ++i) {
//            Edge & e = G[u][i];
//            if (e.cap == 0 && level[e.to] < 0){
//                level[e.to] = level[u] + 1;
//                Q.push(e.to);
//            }
//        }
//    }
//}
//
//int augument(int u,int t,int f){
//    if (u == t) return f;
//
//    for (int i = 0; i < ; ++i) {
//
//    }
//
//}