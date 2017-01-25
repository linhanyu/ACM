//
// Created by Henry on 16/9/24.
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>
using namespace std;

const int MAXV = 16;
const int INF = 0x7FFFFFFF;

int G[MAXV][MAXV];
int n,m;
int level[MAXV];

//dicnic
//struct edge {
//    int to, cap, rev;
//
//    edge() { }
//
//    edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) { }
//};
//
//vector<edge> G[MAXV];
//int level[MAXV];
//int iter[MAXV];
//int n,m;
//
//void addEdge(int u,int v,int cap) {
//    G[u].push_back(edge(v,cap,G[v].size()));
//    G[v].push_back(edge(u,0,G[u].size() - 1));
//}
//
//void bfs(int s) {
//    memset(level,-1,sizeof(level));
//    queue<int> Q;
//    level[s] = 0;
//    Q.push(s);
//    while (!Q.empty()) {
//        int v = Q.front();
//        Q.pop();
//        for (int i = 0; i < G[v].size(); ++i) {
//            edge & e = G[v][i];
//            if (e.cap > 0 && level[e.to]<0) {
//                level[e.to] = level[v] + 1;
//                Q.push(e.to);
//            }
//
//        }
//    }
//}
//
//int dfs(int v,int t,int f) {
//    if (v == t) return f;
//    for (int & i = iter[v];  i < G[v].size(); ++ i) {
//        edge & e = G[v][i];
//        if (e.cap > 0 && level[v] < level[e.to]){
//
//            int d = dfs(e.to,t,min(f,e.cap));
//            if (d>0) {
//                e.cap -= d;
//                G[e.to][e.rev].cap += d;
//                return d;
//            }
//
//        }
//
//    }
//    return 0;
//}
//
//int maxFlow(int s,int t) {
//    int flow = 0;
//    for(;;){
//        bfs(s);
//        if (level[t] < 0) return flow;
//
//        memset(iter,0, sizeof(iter));
//        int f;
//        while((f = dfs(s,t,INF)) > 0)
//            flow += f;
//    }
//
//}

//Ford-Fullkerson
//
//struct edge{
//    int to,cap,rev;
//    edge(){}
//    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
//};
//
//const int MAXN = 1000;
//const int INF = 0x7FFFFFFF;
//vector<edge> G[MAXN + 10];
//bool used[MAXN + 10];
//int n,m;
//
//void addEdge(int from,int to,int cap){
//    G[from].push_back(edge(to,cap,(int)G[to].size()));
//    G[to].push_back(edge(from,0,(int)G[from].size() - 1));
//}
//
//int dfs(int v,int t,int f){
//    if (v == t) return f;
//    used[v] = true;
//
//    for (int i = 0; i < G[v].size(); ++i) {
//        edge & e = G[v][i];
//        if (!used[e.to] && e.cap > 0){
//            int d = dfs(e.to,t,min(f,e.cap));
//            if (d>0){
//                e.cap -= d;
//                G[e.to][e.rev].cap += d;
//                return d;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int maxFlow(int s,int t){
//    int flow = 0;
//    for (;;){
//        memset(used,0, sizeof(used));
//        int f = dfs(s,t,INF);
//        if (f == 0) return flow;
//        flow += f;
//    }
//}
void BFS(int begin){
    queue<int>Q;
    Q.push(begin);

    memset(level,-1, sizeof(level));

    level[begin] = 0;


    while(!Q.empty()){
        int source = Q.front();
        Q.pop();


        for (int i = 1; i <= n; ++i) {
            if (G[source][i] > 0 && level[i] < 0){
                level[i] = level[source] +1;
                Q.push(i);
            }
        }
    }
}


int dfs(int v,int t,int f){
    if (v == t) return f;

    for (int i = 1; i <= n ; ++i) {
        if (G[v][i] > 0 && level[v] < level[i]){
            int d = dfs(i,t,min(f,G[v][i]));
            if (d>0){
                G[v][i] -= d;
                G[i][v] += d;
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
        while ((f=dfs(s,t,INF)) > 0){
            flow += f;
        }
    }


}
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        memset(G,0, sizeof(G));
        for (int i = 0; i < m; ++i) {
            int u,v,cap;
            scanf("%d%d%d",&u,&v,&cap);

            G[u][v] += cap;
        }


        printf("Case %d: %d\n",i,maxFlow(1,n));


    }
}