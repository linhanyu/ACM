//
// Created by Henry on 17/1/17.
//
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cmath>
using namespace std;

const int MAXV = 1000;
const int MAXE = 1000;
const double INF = 1e12;
const double EPS = 1e-8;

struct edge{
    int v,next,c,d;
}G[MAXE];

int head[MAXV];
int cur,n;
double dist[MAXV];
void addedge_(int u,int v,int c,int d){
    G[cur].v = v;
    G[cur].c = c;
    G[cur].d = d;
    G[cur].next = head[u];
    head[u] = cur++;
}



void spfa(int s,double x){
    bool outQ[MAXV];

    fill(dist + 1,dist + 2 + n,INF);
    memset(outQ,1, sizeof(outQ));

    queue<int > Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()){
        s = Q.front();
        Q.pop();
        outQ[s] = true;

        for (int i = head[s]; ~i ; i = G[i].next) {
            double relax = dist[s] + G[i].c * x + G[i].d;
            if (relax <  dist[G[i].v]){
                dist[G[i].v] = relax;
                if (outQ[G[i].v]){
                    outQ[G[i].v] = false;
                    Q.push(G[i].v);
                }
            }
        }

    }
}

double func(double x){
    spfa(1,x);
    return dist[n];
}

double simpson(double L, double R){
    return (R-L)*(func(L) + 4*func((L+R)/2) + func(R))/6.0;
}

double ans(double L,double R){
    double m = (L+R)/2;
    double s0,s1,s2;
    s0 = simpson(L,R);
    s1 = simpson(L,m);
    s2 = simpson(m,R);

    return fabs(s1+s2-s0) <= EPS ? s0 : ans(L,m) + ans(m,R);
}

void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
}

int main()
{
    int m,t;
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int u,v,c,d;
            scanf("%d%d%d%d",&u,&v,&c,&d);
            addedge_(u,v,c,d);
        }
        printf("%.8lf\n",ans(0,t)/t);
    }
    return 0;
}