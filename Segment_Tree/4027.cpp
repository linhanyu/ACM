//
// Created by Henry on 17/1/19.
//

#include <cstdio>
#include <cmath>
#include <algorithm>


#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1

using namespace std;

typedef long long LL;

const int MAXN = 100000 + 10;

LL T[MAXN<<2];

void pushUp(int rt){
    T[rt] = T[L] + T[R];
}

void build(int l,int r,int rt){
    if (l == r){
        scanf("%lld",&T[rt]);
        return;
    }

    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int LB,int RB,int l,int r,int rt){

    if (LB <= l && r <= RB && T[rt] == r-l+1){
        return;
    }

    if (l == r){
        T[rt] = (LL)sqrt(1.0 * T[rt]);
        return;
    }

    int mid = MID;
    if (mid >= LB) update(LB,RB,lson);
    if (mid <  RB) update(LB,RB,rson);
    pushUp(rt);
}

LL query(int LB,int RB,int l,int r,int rt){
    if (LB <= l && r <= RB){
        return T[rt];
    }

    int mid = MID;
    LL ans = 0;

    if (mid >= LB) ans += query(LB,RB,lson);
    if (mid <  RB) ans += query(LB,RB,rson);
    return ans;
}

int main(){
    int n,cnt = 0;
    while (~scanf("%d",&n)){

        printf("Case #%d:\n",++cnt);
        build(1,n,1);

        int q;
        scanf("%d",&q);
        while (q--){
            int op,a,b;
            scanf("%d%d%d",&op,&a,&b);
            if (a > b) swap(a,b);
            if (op){
                printf("%lld\n",query(a,b,1,n,1));
            } else{
                update(a,b,1,n,1);
            }
        }

        puts("");
    }
}