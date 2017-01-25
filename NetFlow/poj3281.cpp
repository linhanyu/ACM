//
// Created by Henry on 16/10/4.
//

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXE = 100000;
const int MAXV = 500 + 10;
const int INF = 0x7FFFFFFF;
const int dst = MAXV-1;
const int src = MAXV-2;

const int offsetCow1 = 101;
const int offsetCow2 = 201;
const int offsetDrink = 301;

struct Node{
    int cap,to,next;
}G[MAXE];

int level[MAXV];
int lAppear[MAXV];
int head[MAXV];
int Gcur[MAXV];
int pre[MAXV];
int cur;

void add_Edge(int u,int v,int cap){
    G[cur].to = v;
    G[cur].cap = cap;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addEdge(int u,int v){
    add_Edge(u,v,1);
    add_Edge(v,u,0);
}

void refBfs(int u){
    memset(level,-1, sizeof(level));
    memset(lAppear,0, sizeof(lAppear));

    queue<int> Q;

    Q.push(u);
    level[u] = 0;
    while (!Q.empty()){
        int s = Q.front();
        Q.pop();

        for (int i = head[s]; ~i; i = G[i].next) {
            if (level[G[i].to] < 0){
                level[G[i].to] = level[s] + 1;
                lAppear[level[G[i].to]]++;
                Q.push(G[i].to);
            }
        }
    }

}

int maxFlow(int s,int t,int n){
    memcpy(Gcur,head, sizeof(Gcur));

    refBfs(t);

    int flow = 0,u;
    pre[s] = u = s;

    while (level[s] < n){
        if (u == t){
            int neck = u,f=INF;
            for (int i = s; i!=t ; i = G[Gcur[i]].to) {
                if (f > G[Gcur[i]].cap){
                    f = G[Gcur[i]].cap;
                    neck = i;
                }
            }

            for (int i = s; i != t ; i = G[Gcur[i]].to) {
                G[Gcur[i]].cap -= f;
                G[Gcur[i]^1].cap += f;
            }

            flow += f;
            u = neck;
        }

        int i;
        for (i = Gcur[u]; ~i  ; i = G[i].next) {
            if (G[i].cap && level[G[i].to] + 1 == level[u]) break;
        }

        if (~i){
            Gcur[u] = i;
            pre[G[i].to] = u;
            u = G[i].to;
        } else{
            if (--lAppear[level[u]] == 0) break;

            int mind = n;
            for (int i = head[u]; ~i ; i = G[i].next) {
                if (G[i].cap && level[G[i].to] < mind){
                    mind = level[G[i].to];
                    Gcur[u] = i;
                }
            }

            level[u] = mind + 1;
            lAppear[level[u]]++;
            u = pre[u];

        }
    }

    return flow;
}


void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

void addInfEdge(int u,int v){
    add_Edge(u,v,INF);
    add_Edge(v,u,0);
}

int main(){
    int n,f,d;
    while (~scanf("%d %d %d",&n,&f,&d)){
        init();


        for (int j = 1; j <= f; ++j) {
            addEdge(src,j);
        }

        for (int j = 1;  j <= d; ++j) {
            addEdge(j + offsetDrink,dst);
        }

        for (int i = 1; i <= n; ++i) {
            int fi,di;
            scanf("%d %d",&fi,&di);
            addEdge(i + offsetCow1,i + offsetCow2);

            for (int j = 0; j < fi; ++j) {
                int v;
                scanf("%d",&v);
                addEdge(v,i + offsetCow1);
//                add_Edge(src,v,INF);
//                add_Edge(v,src,0);
            }

            for (int j = 0; j < di; ++j) {
                int v;
                scanf("%d",&v);
                addEdge(i + offsetCow2,v + offsetDrink);
//                add_Edge(src,v,INF);
//                add_Edge(v,src,0);
            }
        }

        printf("%d\n",maxFlow(src,dst,MAXV));
    }
}