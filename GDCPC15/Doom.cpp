//
// Created by Henry on 17/2/8.
//

#include <cstdio>

#define L rt<<1
#define R rt<<1|1
#define lson l,mid,L
#define rson mid+1,r,R
#define MID (l+r)>>1

typedef unsigned long long LL;

const int MAXN = 100000 + 10;
const LL MOD = 9223372034707292160ULL;


int n,m;
LL A[MAXN],T[MAXN<<2];
bool col[MAXN<<2];

void pushUp(int rt){
    T[rt] = (T[L] + T[R]) % MOD;
    col[rt] = col[L] && col[R];
}

void build(int l,int r,int rt){

    if(l == r){
        col[rt] = 0;
        T[rt] = A[l];
        return;
    }

    int mid = MID;
    build(lson);
    build(rson);
    pushUp(rt);
}

LL query(int LB,int RB,int l,int r,int rt){
    if(LB <= l && r <= RB){
        return T[rt];
    }

    int mid = MID;
    LL ans = 0;
    if (mid >= LB) ans = (ans + query(LB,RB,lson))%MOD;
    if (mid <  RB) ans = (ans + query(LB,RB,rson))%MOD;

    return ans;
}

LL mul_mod(LL a, LL b)
{
    LL res = 0;
    while (b){
        if (b & 1)res = (res + a) % MOD;
        a = (a+a)%MOD;
        b>>=1;
    }
    return res;
}



void update(int LB,int RB,int l,int r,int rt){
    if (col[rt]) return;

    if (l == r){
        LL tmp  = mul_mod(T[rt],T[rt]);
        if (tmp == T[rt]) col[rt] = 1;
        T[rt] = tmp;
        return;
    }
    int mid = MID;
    if (mid >= LB) update(LB,RB,lson);
    if (mid <  RB) update(LB,RB,rson);
    pushUp(rt);
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d:\n",cases);

        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n ; ++i) scanf("%llu",&A[i]);

        build(1,n,1);
        LL ans = 0;

        while (m--){
            int l,r;
            scanf("%d%d",&l,&r);
            ans = (ans + query(l,r,1,n,1))%MOD;
            update(l,r,1,n,1);
            printf("%llu\n",ans);
        }
    }
}