//
// Created by Henry on 16/11/3.
//
/*
HDU 4035

    dp求期望的题。
    题意：
    有n个房间，由n-1条隧道连通起来，实际上就形成了一棵树，
    从结点1出发，开始走，在每个结点i都有3种可能：
        1.被杀死，回到结点1处（概率为ki）
        2.找到出口，走出迷宫 （概率为ei）
        3.和该点相连有m条边，随机走一条
    求：走出迷宫所要走的边数的期望值。

    设 E[i]表示在结点i处，要走出迷宫所要走的边数的期望。E[1]即为所求。

    叶子结点：
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)*(E[father[i]] + 1);
         = ki*E[1] + (1-ki-ei)*E[father[i]] + (1-ki-ei);

    非叶子结点：（m为与结点相连的边数）
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)/m*( E[father[i]]+1 + ∑( E[child[i]]+1 ) );
         = ki*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei)/m*∑(E[child[i]]) + (1-ki-ei);

    设对每个结点：E[i] = Ai*E[1] + Bi*E[father[i]] + Ci;

    对于非叶子结点i，设j为i的孩子结点，则
    ∑(E[child[i]]) = ∑E[j]
                   = ∑(Aj*E[1] + Bj*E[father[j]] + Cj)
                   = ∑(Aj*E[1] + Bj*E[i] + Cj)
    带入上面的式子得
    (1 - (1-ki-ei)/m*∑Bj)*E[i] = (ki+(1-ki-ei)/m*∑Aj)*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei) + (1-ki-ei)/m*∑Cj;
    由此可得
    Ai =        (ki+(1-ki-ei)/m*∑Aj)   / (1 - (1-ki-ei)/m*∑Bj);
    Bi =        (1-ki-ei)/m            / (1 - (1-ki-ei)/m*∑Bj);
    Ci = ( (1-ki-ei)+(1-ki-ei)/m*∑Cj ) / (1 - (1-ki-ei)/m*∑Bj);

    对于叶子结点
    Ai = ki;
    Bi = 1 - ki - ei;
    Ci = 1 - ki - ei;

    从叶子结点开始，直到算出 A1,B1,C1;

    E[1] = A1*E[1] + B1*0 + C1;
    所以
    E[1] = C1 / (1 - A1);
    若 A1趋近于1则无解...

*/
#include <cstdio>
#include <memory.h>
#include <cmath>
#define EPS 1e-9
using namespace std;

const int MAXN = 10000 + 10;
const int MAXE = 2*MAXN;

double e[MAXN];
double k[MAXN];
double dp[MAXN];
double A[MAXN],B[MAXN],C[MAXN];

struct edge{
    int next,v;
}G[MAXE];

int head[MAXN];
int eNum[MAXN];
int n,cur;

void addEdge_(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void addEdge(int u,int v){
    addEdge_(u,v);
    addEdge_(v,u);
}


bool dfs(int t,int pre){
    int m = eNum[t];
    A[t] = k[t];
    B[t] = (1-k[t]-e[t])/m;
    C[t] = 1-k[t]-e[t];

    double tmp = 0;
    for (int i = head[t]; ~i ; i = G[i].next) {
        if (G[i].v == pre) continue;
        if (!dfs(G[i].v,t)) return false;

        A[t] += (1-k[t]-e[t])/m*A[G[i].v];
        C[t] += (1-k[t]-e[t])/m*C[G[i].v];
        tmp += (1-k[t]-e[t])/m*B[G[i].v];
    }

    if (fabs(tmp-1) < EPS) return false;

    A[t] /= 1-tmp;
    B[t] /= 1-tmp;
    C[t] /= 1-tmp;

    return true;
}

void solve(){
    if(dfs(1,-1)&&fabs(1-A[1])>EPS)
    {
        printf("%.6lf\n",C[1]/(1-A[1]));
    }
    else printf("impossible\n");

}

void init(){
    memset(dp,0, sizeof(dp));
    memset(head,-1, sizeof(head));
    memset(eNum,0, sizeof(eNum));
    cur = 0;
}
int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        init();

        printf("Case %d: ",cases);

        scanf("%d",&n);

        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            addEdge(x,y);
            eNum[x]++;
            eNum[y]++;
        }

        for (int i = 0; i < n ; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            k[i] = 1.0*x/100;
            e[i] = 1.0*y/100;
        }

        solve();
    }
}