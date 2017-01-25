//
// Created by Henry on 16/11/29.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long LL;

#define MID(a,b) ((a+b)>>1)
#define L(rt) rt<<1
#define R(rt) rt<<1|1
#define lson left,mid,L(rt)
#define rson mid+1,right,R(rt)

const LL MAXN = 100000 + 10;


pair<LL,LL > h[MAXN];

LL T[MAXN << 2],dp[MAXN],r[MAXN],pos[MAXN];

bool cmp(const pair<LL,LL> & a,const pair<LL,LL> & b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void Pushup(LL rt){
    T[rt] = max(T[R(rt)],T[L(rt)]);
}

void build(LL left,LL right ,LL rt){
    if (left == right){
        T[rt] = -1;
        return;
    }

    LL mid = MID(left,right);

    build(lson);
    build(rson);
    Pushup(rt);
}

void update(LL pos,LL val,LL left,LL right, LL rt){
    if (left == right){
        T[rt] = val;
        return;
    }

    LL mid = MID(left,right);
    if (pos <= mid) update(pos,val,lson);
    else update(pos,val,rson);

    Pushup(rt);
}

LL query(LL L,LL R,LL left,LL right, LL rt){
    if(L <= left  && right <= R) return T[rt];

    LL mid = MID(left,right);

    LL res = -1;
    if (L <= mid) res = max(res,query(L,R,lson));
    if (R > mid) res = max(res,query(L,R,rson));

    return res;
}


int main(){
    LL t;
    scanf("%lld",&t);

    for (LL cases = 1; cases <= t; ++cases) {

        LL n,l;
        scanf("%lld%lld",&n,&l);

        build(0,n,1);

        for (LL i = 1; i <= n ; ++i) {
            scanf("%lld",&h[i].first);
            h[i].second = i;
        }

        sort(h + 1,h + 1 + n,cmp);

        update(0,0,0,n,1);
        for (LL i = 1; i <= n; ++i) {
            dp[h[i].second] = -1;
            LL ans = query(max(h[i].second - l,0ll),h[i].second - 1,0,n,1);

            if (ans == -1) continue;

            dp[h[i].second] = ans + h[i].first*h[i].first;

            if (h[i].second == n) break;

            update(h[i].second,dp[h[i].second] - h[i].first,0,n,1);
        }

        if(~dp[n]){
            printf("Case #%lld: %lld\n",cases,dp[n] );
        } else{
            printf("Case #%lld: No solution\n",cases);
        }

    }
}