//
// Created by Henry on 16/10/8.
//

#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100+10;
//const int INF = 0x7FFFFFF;
int UFSet[MAXN];

struct edge{
    int u,v,weight;
    edge(){}
    edge(int u,int v,int w):u(u),v(v),weight(w){}

    bool operator<(const edge & e2) const{
        return weight > e2.weight;
    }
};

priority_queue<edge> Q;

int Find(int rt){
    if (UFSet[rt] < 0)
        return rt;
    else{
        return UFSet[rt] = Find(UFSet[rt]);
    }
}

void Merge(int root1,int root2){
    root1 = Find(root1);
    root2 = Find(root2);

    if (root1 == root2){
        return;
    }

    if (UFSet[root1] < UFSet[root2]){
        //阶为负数.值小则绝对值大,阶大
        UFSet[root2] = root1;

    } else{
        if (UFSet[root1] == UFSet[root2]){
            UFSet[root2]--;
        }

        UFSet[root1] = root2;
    }
}


void init(){
    memset(UFSet,-1, sizeof(UFSet));
}
int Kruscal(priority_queue<edge> & Q){
    init();
    int res = 0;
    while(!Q.empty()){
        edge e = Q.top();
        Q.pop();

        if (Find(e.u) != Find(e.v)){
            Merge(e.u,e.v);
            res+=e.weight;
        }
    }
    return res;
}

int main(){

    int n;
    while (~scanf("%d",&n) && n){
        for (int i = 0; i < n*(n-1)/2; ++i) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            Q.push(edge(u,v,w));
        }

        printf("%d\n",Kruscal(Q));
    }
}