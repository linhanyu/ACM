//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>

const int MAXM = 3000 + 10;
const int MAXN = 100 + 10;


using namespace std;

//Star

struct node{
    int u,v;
    double w;

    bool operator<(const node & n) const {
        return w < n.w;
    }
}G[MAXM];
int cur;
int x[100],y[100];

void addedge(int i,int j){
    G[cur].u = i;
    G[cur].v = j;
    G[cur].w = sqrt(pow(x[i] - x[j],2) + pow(y[i] - y[j] , 2));
    cur++;
}

void initStar(){
    cur = 0;
}

//UFSet

int UFSet[MAXN];

void initUFSet(){
    memset(UFSet,-1, sizeof(UFSet));
}

int Find(int rt){ return UFSet[rt] < 0 ? rt : UFSet[rt] = Find(UFSet[rt]);}

void Merge(int rt1,int rt2){
    if (rt1 == rt2) return;

    UFSet[rt1] = rt2;
}

//Kruscal

bool inTree[MAXM];
int st,dt;
double Kruscal(){
    sort(G,G+cur);
    double ans = 0;
    for (int i = 0; i < cur; ++i) {

        int rt1 = Find(G[i].u);
        int rt2 = Find(G[i].v);

        if (rt1 == rt2) continue;

        Merge(rt1,rt2);
        ans += G[i].w;
    }

    return ans;
}

void initKruscal(){
    memset(inTree,0, sizeof(inTree));
}

//main
int main(){
    int t;
    while (~scanf("%d",&t) && t){
        initStar();
        initUFSet();
        initKruscal();

        scanf("%d%d",&st,&dt);
        st--;
        dt--;
        if (st < dt) swap(st,dt);

        for (int i = 0; i < t; ++i) scanf("%d%d",&x[i],&y[i]);

        double ans = 0;
        for (int i = 1; i < t; ++i) {
            for (int j = 0; j < i; ++j) {
                addedge(i,j);
                if (i == st && j == dt){
                    Merge(i,j);
                    ans += G[cur - 1].w;
                }
            }
        }

        printf("%.2lf\n",ans + Kruscal());
    }
}