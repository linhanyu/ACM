//
// Created by Henry on 16/11/27.
//
//TODO

#include <cstdio>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN =  100000 + 10;
const int INF = 1000000000 + 10;

struct edge{
    int u,v,next;
}G[MAXN];

int head[MAXN];
int dep[MAXN];
int pre[MAXN];
int val[MAXN];
int son[MAXN];
int sz[MAXN];
int father[MAXN];
int ti[MAXN];
int top[MAXN];
int cot[MAXN];
int a[MAXN];

int cur,idx;


void init(){
    memset(head,-1, sizeof(head));
    cur = 0;
    father[1] = sz[0] = 0;
    dep[1] = idx = 1;

}

void addedge(int u,int v){
    G[cur].u = u;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur ++;
}

//树链剖分
void findSon(int u){

    son[u] = 0;
    sz[u] = 1;
    //size
    for (int i = head[u]; ~i ; i = G[u].next) {
        int v = G[i].v;
        if (v == father[u]) continue;
        dep[v] = dep[u] + 1;
        father[v] = u;
        findSon(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}

void findTime(int u,int fa){
    ti[u] = idx++;
    //在线段树中编号
    top[u] = fa;
    //该点所在链顶点
    cot[ti[u]] = a[u];
    //点权
    if (son[u] != 0) findTime(son[u],top[u]);
    //重边
    for (int i = head[u]; ~i ; i = G[i].next) {
        if (G[i].v == father[u] || G[i].v == son[u]) continue;
        findTime(G[i].v,G[i].v);
        //轻边
    }
}

//线段树
struct Tree{
    int R,L,Rn,Ln,Len;
    int ml,Rl,Ll;
    int dml,dR1,dLl;
};
void buildTree(int L,int R,int rt){

}

//测试

int main(){
    int t;
    scanf("%d",&t);



    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d:\n",cases);

        init();

        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&a[i]);
        }

        for (int i = 2; i <= n; ++i) {
            int tmp;
            scanf("%d",&tmp);
            addedge(tmp,i);
        }

        findSon(1);
        findTime(1,1);

    }
}