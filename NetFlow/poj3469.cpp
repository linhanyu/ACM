//
// Created by Henry on 16/10/5.
//

#include <cstdio>
#include <memory>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXV = 20000 + 10;
const int MAXE = 900000;
const int src = MAXV-1;
const int dst = MAXV-2;
const int INF = 0x6FFFFFFF;
struct Edge{
    int cap,to,next;
}G[MAXE];

int cur;

int head[MAXV];
int lAppear[MAXV];
int level[MAXV];
int Gcur[MAXV];
int pre[MAXV];

void revBfs(int u){
    memset(level,-1, sizeof(level));
    memset(lAppear,0, sizeof(lAppear));

    queue<int > Q;

    Q.push(u);
    level[u] = 0;
    lAppear[0] = 1;

    while (!Q.empty()){
        u = Q.front();
        Q.pop();

        for (int i = head[u]; ~i  ; i = G[i].next) {
            if (level[G[i].to] < 0){
                level[G[i].to] = level[u] + 1;
                lAppear[level[G[i].to]] ++;
                Q.push(G[i].to);

            }
        }

    }
}


int maxFlow(int s,int t,int n){
    memcpy(Gcur,head, sizeof(Gcur));

    revBfs(t);
    int flow=0,u;

    pre[s] = u = s;

    while (level[u] < n){
        if (u == t) {

            int f = INF, neck = u;
            for (int i = s; i != t; i = G[Gcur[i]].to) {
                if (G[Gcur[i]].cap < f) {
                    f = G[Gcur[i]].cap;
                    neck = i;
                }
            }


            for (int i = s; i != t; i = G[Gcur[i]].to) {
                G[Gcur[i]].cap -= f;
                G[Gcur[i] ^ 1].cap += f;
            }

            flow += f;
            u = neck;
        }

        int i;
        for (i = Gcur[u];  ~i ; i = G[i].next) {
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
                    mind = level[G[i].to] ;
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


void add_Node(int u,int v,int cap){
    G[cur].to = v;
    G[cur].cap = cap;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addNode(int u,int v,int cap){
    add_Node(u,v,cap);
    add_Node(v,u,0);
}


void init(){

    cur =0;
    memset(head,-1, sizeof(head));
}


int main(){
    int n,m;
    while (~scanf("%d %d",&n,&m)){
        init();

        for (int i = 1; i <= n; ++i) {
            int ai,bi;
            scanf("%d %d",&ai,&bi);

            addNode(src,i,ai);
            addNode(i,dst,bi);
        }

        for (int i = 0; i < m; ++i) {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);

            addNode(a,b,w);
            addNode(b,a,w);
        }

        printf("%d\n",maxFlow(src,dst,n+1));
    }
}