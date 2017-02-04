//
// Created by Henry on 17/1/26.
//

#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

const int MAXE = 50000 + 10;
const int MAXV = 300 + 10;

struct edge{
    int a,b,t,next,v;
}G[MAXE];

int head[MAXV],dist[MAXV];
int cur;

void spfa(int s){
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

        for (int i = head[s]; ~i; i = G[i].next) {
            int moment = dist[s]%(G[i].a+G[i].b);

            int relax;
            if (moment + G[i].t <= G[i].a){
                //正在打开,且足够时间穿过
                relax = dist[s] + G[i].t;
            } else{
                //等下次打开
                relax = dist[s] + G[i].t + G[i].a + G[i].b - moment;
            }

            if (relax < dist[G[i].v]){
                dist[G[i].v] = relax;
                if (outQ[G[i].v]){
                    outQ[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }
}

void addedge_(int u,int v,int a,int b,int t){
    G[cur].v = v;
    G[cur].a = a;
    G[cur].b = b;
    G[cur].t = t;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init() {
    memset(head, -1, sizeof(head));
    cur = 0;
}

int main(){
    int n,m,s,t,cases = 0;
    while (~scanf("%d%d%d%d",&n,&m,&s,&t)){
        init();
        for (int i = 0; i < m; ++i) {
            int u,v,a,b,ti;
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&ti);
            if (a < ti) continue;
            addedge_(u,v,a,b,ti);
        }
        spfa(s);

        printf("Case %d: %d\n",++cases,dist[t]);
    }
}