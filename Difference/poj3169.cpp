//
// Created by Henry on 16/10/11.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXE = 20000 + MAXN;
const int INF = 0x3f3f3f3f;
struct edge{
    int v,cost,next;
}G[MAXE];

int head[MAXN];
int dis[MAXN];

int cur;

void add_Node(int u,int v,int cost){
    G[cur].cost = cost;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}


bool spfa(int begin,int end,int num){
    static bool outqueue[MAXN];
    static int In[MAXN];


    fill(dis + begin,dis + num + 1,INF);
    memset(outqueue,1, sizeof(outqueue));
    memset(In,0, sizeof(In));
    queue<int > Q;

    Q.push(begin);
    dis[begin] = 0;

    while (!Q.empty()){
        int s = Q.front();
        Q.pop();
        outqueue[s] = true;

        for (int i = head[s]; ~i  ; i = G[i].next) {
            if ( dis[s] + G[i].cost < dis[G[i].v]){
                dis[G[i].v] = dis[s] + G[i].cost;
                if (In[G[i].v]++ >= num)
                    return false;

                if (outqueue[G[i].v]){
                    outqueue[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }
    }

    return true;

}

int main(){
    int n,ml,md;

    while (~scanf("%d %d %d",&n,&ml,&md)){
        init();

        for (int i = 0; i < ml; ++i) {
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            if (a > b) swap(a,b);
            add_Node(a,b,d);

        }

        for (int i = 0; i < md; ++i) {
            int a,b,d;
            scanf("%d %d %d",&a,&b,&d);
            if (a > b) swap(a,b);
            add_Node(b,a,-d);
        }

        for (int i = 1; i <= n ; ++i) {
            add_Node(0,i,0);
        }


        if (spfa(0,n,n+1)){
            if (spfa(1,n,n) && dis[n] != INF){

                printf("%d\n",dis[n]);
            } else{
                puts("-2");
            }


        } else{
            puts("-1");

        }
    }
}