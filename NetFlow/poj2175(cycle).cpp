//
// Created by Henry on 16/10/5.
//

#include <cstdio>
#include <memory>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#define ABS(a) ((a) > 0 ? (a) : -(a))

using namespace std;


//
const int MAXN = 110;
const int MAXE = 30500;
const int MAXV = 300;
const int INF = 0x6FFFFFFF;
//
int src,dst,n,m;
int x[MAXN],y[MAXN],b[MAXN],q[MAXN],c[MAXN],p[MAXN];
//
//struct edge{
//    int to,cap,cost,rev;
//    edge(){}
//    edge(int t,int c,int cost,int rev):to(t),cap(c),cost(cost),rev(rev){}
//};
//
//typedef pair<int,int> P;
//int V;
//vector<edge> G[MAXV];
//int h[MAXV];
//int dist[MAXV];
//int src,dst;
//int prevv[MAXV],preve[MAXV];
////int GM[MAXV][MAXV];
//void addNode(int u,int v,int cap,int cost){
//    G[u].push_back(edge(v,cap,cost,G[v].size()));
//    G[v].push_back(edge(u,0,-cost,G[u].size() - 1));
//}
//
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
struct node{
    int to,next,cap,cost;
}G[MAXE];

int cur;

int GM[MAXV][MAXV];
int preve[MAXV];
int head[MAXV];
int dis[MAXV];
int negV;


int spfa(int begin,int end,int n){
    static bool outqueue[MAXV];
    static int in[MAXV];
    memset(outqueue,1, sizeof(outqueue));
//    fill(dis,dis+MAXV,INF);
    memset(dis,0x3F, sizeof(dis));
    memset(in,0, sizeof(in));

    stack<int > Q;
    Q.push(begin);

    dis[begin] = 0;
    in[begin] = 1;

    while (!Q.empty()){
        int s = Q.top();
        Q.pop();
        outqueue[s] = true;

        for (int i = head[s]; ~i  ; i = G[i].next) {
            if (G[i].cap && dis[G[i].to] > dis[s] + G[i].cost){
                dis[G[i].to] = dis[s] + G[i].cost;
                preve[G[i].to] = i;

                if (++in[G[i].to]  >= n)
                {
                    negV = G[i].to;
                    return -1;
                }

                if (outqueue[G[i].to]){
                    outqueue[G[i].to] = false;
                    Q.push(G[i].to);
                }

            }
        }
    }

    return dis[end];
}
//
//int mincost(int s,int t,int f){
//    int res = 0;
//    while (f > 0 && ~spfa(s,t)){
//        int d = INF;
//        for (int i = t; i != s ; i = G[preve[i] ^ 1].to) {
//            d = min(d,G[preve[i]].cap);
//        }
//
//        f -= d;
//        res += dis[t] * d;
//
//        for (int i = t; i != s ; i = G[preve[i] ^ 1].to) {
//            G[preve[i]].cap -= d;
//            G[preve[i] ^ 1].cap += d;
//        }
//    }
//
//    return res;
//}

void add_Node(int u,int v,int cap,int cost){
    GM[u][v] = cur;
    G[cur].cap = cap;
    G[cur].to = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur ++;
}

void addNode(int u,int v,int cap,int cost){
    add_Node(u,v,cap,cost);
    add_Node(v,u,0,-cost);
}

void init(){
    src  = m+n;
    dst = src+1;
    cur = 0;
    memset(head,-1, sizeof(head));
}




void augument(){
    static bool vis[MAXV];

    memset(vis,0, sizeof(vis));

    int u;

    for (u = negV; !vis[u] ; u = G[preve[u] ^ 1].to) {
        vis[u] = true;
    }

    int f = INF;
    bool flg = true;
    for (int i = u; i != u || flg; i = G[preve[i] ^ 1].to) {
        f = min(G[preve[i]].cap,f);
        flg = false;
    }


    flg = true;
    for (int i = u; i != u || flg ; i = G[preve[i] ^ 1].to) {
        G[preve[i]].cap -= f;
        G[preve[i] ^ 1].cap += f;
        flg = false;
    }


}

void solve(){
    init();
    static int fj[MAXV],fi;
//    int cost=0,F=0;

    memset(fj,0, sizeof(fj));
    fi = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d",&tmp);
            fj[j] += tmp;
            int c = ABS(x[i] - p[j]) + ABS(y[i] - q[j]) + 1;
            add_Node(i,j+n,INF,c);
            add_Node(j+n,i,tmp,-c);
//            cost += e[i][j] * c;
        }
    }

    for (int i = 0; i < n; ++i) {
        addNode(src,i,b[i],0);
//        F += b[i];
    }

    for (int i = 0; i < m; ++i) {
        add_Node(i+n,dst,c[i]-fj[i],0);
        add_Node(dst,i+n,fj[i],0);
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            G[GM[i][j+n]].cap -= e[i][j];
//            G[GM[j+n][i]].cap += e[i][j];
//        }
//    }

    int k = spfa(src,dst,m+n+2);
//
    if (~k){
        puts("OPTIMAL");
    } else{
        augument();
        puts("SUBOPTIMAL");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d%c",G[GM[j+n][i]].cap,j+1 == m ? '\n' : ' ');
            }
        }

    }

//    if (mincost(src,dst,F) < cost){
//        puts("SUBOPTIMAL");
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                printf("%d%c",G[GM[j+n][i]].cap,j+1 == m ? '\n' : ' ');
//            }
//        }
//    } else{
//        puts("OPTIMAL");
//    }
}

int main(){

    while (~scanf("%d %d",&n,&m)){
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d",&x[i],&y[i],&b[i]);

        }

        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d",&p[j],&q[j],&c[j]);
        }

//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                scanf("%d",&e[i][j]);
//            }
//        }

        solve();
    }
}