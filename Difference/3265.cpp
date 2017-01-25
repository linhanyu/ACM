//
// Created by Henry on 16/10/15.
//

#include <cstdio>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXE = 330000;
const int MAXV = 900;
const double INF = 99999999999;

struct edge{
    int next,v;
    double cost;
}G[MAXE];

int head[MAXV];
int cur ;

double dis[MAXV];
bool Instack[MAXV];
bool vis[MAXV];
void add_Edge(int u,int v, double cost){
    G[cur].cost = cost;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

bool dfs(int u){
    if (Instack[u]) return false;
    Instack[u] = true;

    for (int i = head[u]; ~i ; i = G[i].next) {
        double tmp = dis[u] + G[i].cost;
        if(tmp < dis[G[i].v]){
            dis[G[i].v] = tmp;
            if (!dfs(G[i].v)) return false;
        }
    }

    Instack[u] = false;
    return true;
}

bool spfa(int num){
    int i,u,v,cnt=0;
    memset(vis,0,sizeof(vis));
    memset(Instack,0,sizeof(Instack));
    //memset(cnt,0,sizeof(cnt));
    for(i=0;i<num;i++)
    {
        dis[i]=0;
        //que.push(i);
    }
    for(i=1;i<=num;i++)
    {
        if(!vis[i])
        {
            if(!dfs(i))
            {
                return false;
            }
        }
    }
    return true;
}

//
//bool spfa(int begin,int num){
//    static int In[MAXV];
//    static bool Outqueue[MAXV];
//
//    memset(In,0, sizeof(int) * (num+1));
//    memset(Outqueue,1, sizeof(bool) * (num+1));
//
//    fill(dis,dis+num,INF);
//    num = (int)sqrt(1.0*(num));;
//
//    queue<int > Q;
//    Q.push(begin);
//    In[begin] = 1;
//    dis[begin] = 0;
//
//    while (!Q.empty()){
//        int s = Q.front();
//        Q.pop();
//        Outqueue[s] = true;
//
//        for (int i = head[s]; ~i ; i = G[i].next) {
//            double tmp = dis[s] + G[i].cost;
//            if (tmp < dis[G[i].v]){
//                dis[G[i].v] = tmp;
//
//
//
//                if (Outqueue[G[i].v]){
//                    if (++In[G[i].v] >= num) return false;
//                    Outqueue[G[i].v] = false;
//                    Q.push(G[i].v);
//                }
//            }
//        }
//    }
//
//    return true;
//
//}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

int main(){
    int n,m;
    double l,u;
    while (~scanf("%d %d %lf %lf",&n,&m,&l,&u)){
        init();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                double tmp;
                scanf("%lf",&tmp);
                add_Edge(j+n,i,log(u/tmp));
                add_Edge(i,j+n,-log(l/tmp));
            }
        }


//
//
//        for (int i = 0; i < n + m; ++i) {
//            add_Edge(m+n,i,0);
//        }

        if (spfa(n+m)){
            puts("YES");
        } else{
            puts("NO");
        }
    }
}