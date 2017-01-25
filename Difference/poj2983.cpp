//
// Created by Henry on 16/10/11.
//
#include<cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

const int MAXV = 1000 + 10;
const int MAXE = 200000 + MAXV;
const int NegInf = -0x3f3f3f3f;

struct Edge{
    int v,next,cost;
}G[MAXE];

int head[MAXV];
int dis[MAXV];

int cur;


void addEdge(int u,int v,int cost){
    G[cur].v = v;
    G[cur].cost = cost;
    G[cur].next = head[u];
    head[u] = cur++;
}

bool spfa(int begin,int num){
    static bool Outqueue[MAXV];
    static int In[MAXV];

    memset(In,0, sizeof(In));
    memset(Outqueue,1, sizeof(Outqueue));
    fill(dis+begin,dis + num + 1,NegInf);

    queue<int > Q;
    Q.push(begin);
    dis[begin] = 0;

    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        Outqueue[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next) {
            int tmpDis = dis[s] + G[i].cost;

            if (tmpDis > dis[G[i].v]){
                dis[G[i].v] = tmpDis;

                if (In[G[i].v]++ >= num) return false;

                if (Outqueue[G[i].v]){
                    Q.push(G[i].v);
                    Outqueue[G[i].v] = false;
                }

            }


        }
    }

    return true;

}



void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

int main(){
    int n,m;
    while (~scanf("%d %d",&n,&m)){

        init();

        for (int i = 0; i < m; ++i) {
            getchar();

            char c;
            int op1,op2,op3;
            scanf("%c",&c);
            if (c == 'P'){
                scanf("%d %d %d",&op1,&op2,&op3);
                addEdge(op1,op2,op3);
                addEdge(op2,op1,-op3);

            } else{
                scanf("%d %d",&op1,&op2);
                addEdge(op1,op2,1);
            }
        }

        for (int i = 1; i <= n; ++i) {
            addEdge(0,i,0);
        }

        if (spfa(0,n+1)){
            puts("Reliable");
        } else{
            puts("Unreliable");
        }


    }
}
