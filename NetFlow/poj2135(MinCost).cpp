//
// Created by Henry on 16/10/5.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;

const int MAXV = 1000 + 10;
const int MAXE = 50000;
const int INF = 0x6FFFFFF;

struct edge{
    int to,cap,cost,next;
}Buffer[MAXE];

int cur;
int head[MAXV];
int pre[MAXV];
int pree[MAXV];
int dis[MAXV];

int spfa(int begin,int end){
    static bool outqueue[MAXV];

    fill(dis,dis+MAXV,INF);
    memset(outqueue,1, sizeof(outqueue));

    queue<int > Q;
    Q.push(begin);

    dis[begin] = 0;
    pre[begin] = -1;

    while (!Q.empty()){
        int s =Q.front();
        Q.pop();
        outqueue[s] = true;

        for (int i = head[s]; ~i ; i = Buffer[i].next) {

            if (Buffer[i].cap > 0 && dis[Buffer[i].to] > dis[s] + Buffer[i].cost){
                dis[Buffer[i].to] = dis[s] + Buffer[i].cost;
                pre[Buffer[i].to] = s;
                pree[Buffer[i].to] = i;

                if (outqueue[Buffer[i].to]){
                    Q.push(Buffer[i].to);
                    outqueue[Buffer[i].to] = false;
                }

            }
        }
    }

    return dis[end] == INF ? -1:dis[end];


}

int MinCostFlow(int s,int t,int f){
    int ans = 0;
    while(~spfa(s,t) && f>0){
        int d = INF;
        for (int i = t; i !=s ; i = pre[i]) {
            d = min(d,Buffer[pree[i]].cap);
        }

        ans += d * dis[t];
        f -= d;

        for (int i = t; i !=s ; i = pre[i]) {
            Buffer[pree[i]].cap -= d;
            Buffer[pree[i] ^ 1].cap += d;
        }

    }

    return ans;
}

void add_Edge(int u,int v,int cap,int cost){
    Buffer[cur].to = v;
    Buffer[cur].cap = cap;
    Buffer[cur].cost = cost;
    Buffer[cur].next = head[u];
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
//    int to,cap,cost,rev;
//    edge(){}
//    edge(int t,int c,int cost,int rev):to(t),cap(c),cost(cost),rev(rev){}
//};
//
//
//int V;
//vector<edge> G[MAXV];
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
//        priority_queue<P,vector<P>,greater<P> > Q;
//        fill(dist,dist+V,INF);
//        dist[s] = 0;
//        Q.push(P(0,s));
//
//        while(!Q.empty()){
//            P p = Q.top();
//            Q.pop();
//
//            int v = p.second;
//
//            if (dist[v] < p.first) continue;
//
//            for (int i = 0; i < G[v].size(); ++i) {
//                edge & e = G[v][i];
//                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
//                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
//                    prevv[e.to] = v;
//                    preve[e.to] = i;
//                    Q.push(P(dist[e.to],e.to));
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
//            G[e.to][e.rev].cap += d;
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
        printf("%d\n",MinCostFlow(0,n-1,2));
    }
}