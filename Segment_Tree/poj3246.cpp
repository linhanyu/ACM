//
// Created by Henry on 17/1/19.
//
#include<cstdio>
#include <algorithm>
#include <memory.h>

#define L (rt<<1)
#define R (rt<<1|1)
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1

using namespace std;

const int MAXN = 50000 + 10;
const int INF = 0x3f3f3f3f;

int Tmin[MAXN<<2],Tmax[MAXN<<2];

void pushUp(int rt){
    Tmin[rt] = min(Tmin[L],Tmin[R]);
    Tmax[rt] = max(Tmax[L],Tmax[R]);
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%d",&Tmin[rt]);
        Tmax[rt] = Tmin[rt];
        return;
    }

    int mid = MID;

    build(lson);
    build(rson);

    pushUp(rt);
}

int queryMax(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return Tmax[rt];
    }

    int mid = MID;

    int ans = 0;
    if (mid >= LB) ans = max(ans,queryMax(LB,RB,lson));
    if (mid <  RB) ans = max(ans,queryMax(LB,RB,rson));
    return ans;
}

int queryMin(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return Tmin[rt];
    }

    int mid = MID;

    int ans = INF;
    if (mid >= LB) ans = min(ans,queryMin(LB,RB,lson));
    if (mid <  RB) ans = min(ans,queryMin(LB,RB,rson));
    return ans;
}


int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        build(1,n,1);

        while (q--){
            int a,b;
            scanf("%d%d",&a,&b);

            printf("%d\n",queryMax(a,b,1,n,1) - queryMin(a,b,1,n,1));
        }
    }
}