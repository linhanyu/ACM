//
// Created by Henry on 16/10/11.
//

#include <cstdio>
#include <memory>
#include <queue>
#include <algorithm>

using namespace std;

const int offset[][2] = {{-1,0},{1,0},{0,1},{0,-1}};

const int MAXN = 100 + 10;
const int MAXV = MAXN * MAXN + 10;
const int MAXE = 10 * MAXV;

const int INF = 0x7FFFFFFF;

struct Edge{
    int cost,cap,v,next;
}G[MAXE];

int cur;
int src,dst;
int n,m;

int head[MAXV];
int dis[MAXV];
int preve[MAXV];

bool outbound(int r,int c){
    return r < 0 || c<0 || r>=n || c>=m;
}



int spfa(int begin,int end){
    static bool Outqueue [MAXV];

    memset(Outqueue,1, sizeof(Outqueue));

    fill(dis,dis + dst + 1,INF);
    queue<int > Q;

    Q.push(begin);
    dis[begin] = 0;

    while (!Q.empty()){
        int s = Q.front();
        Q.pop();
        Outqueue[s] = true;

        for (int i = head[s]; ~i  ; i = G[i].next) {
            if (G[i].cap && G[i].cost + dis[s] < dis[G[i].v]){
                dis[G[i].v] = G[i].cost + dis[s];
                preve[G[i].v] = i;

                if (Outqueue[G[i].v]){
                    Outqueue[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }

    }

    return dis[end] == INF ? -1:dis[end];
}

int MinCostMaxFlow(int s,int t){
    int res = 0;
    while (~spfa(s,t)){
        int f = INF;
        for (int i = t ; i != s ; i = G[preve[i] ^ 1].v) {
            f = min(f,G[preve[i]].cap);
        }

        res += f * dis[t];

        for (int i = t ; i != s ; i = G[preve[i] ^ 1].v) {
            G[preve[i]].cap -= f;
            G[preve[i] ^ 1].cap += f;
        }


    }

    return res;
}


void add_node(int u,int v,int cap,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].cap = cap;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addNode(int u,int v,int cap,int cost){
    add_node(u,v,cap,cost);
    add_node(v,u,0,-cost);
}

void init(){
    cur = 0;
    memset(head,-1, sizeof(head));
}

void addNode2D(int x,int y,int node){
    for (int i = 0; i < 4; ++i) {
        int dx = x+offset[i][0];
        int dy = y+offset[i][1];

        if (outbound(dx,dy)) continue;

        addNode(node,dx * m  + dy,INF,1);
        addNode(dx * m  + dy,node,INF,1);

    }
}

int main(){

    while(~scanf("%d%d",&n,&m) && (n || m)){
        init();
        getchar();

        src = n*m;
        dst = src + 1;
        char tmp;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%c" ,&tmp);
                addNode2D(i,j,i*m + j);
                if (tmp == 'H'){
                    addNode(i*m + j,dst,1,0);
                }else if (tmp == 'm'){
                    addNode(src,i*m + j,1,0);
                }
            }
            getchar();
        }

        printf("%d\n",MinCostMaxFlow(src,dst));
    }

}