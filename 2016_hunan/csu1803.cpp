//
// Created by Henry on 17/1/15.
//
#include <cstdio>
#include <memory.h>
const int MAXN = 2017;

typedef long long LL;

//LL dp[MAXN][MAXN];
LL dp[MAXN][MAXN];

//
//void init(){
//    memset(dp,0, sizeof(dp));
//    for (int i = 1; i < MAXN; ++i) {
//        for (int j = 1; j < MAXN; ++j) {
//            if(((i%2016)*(j%2016))%2016 == 0) dp[i][j]++;
//        }
//    }
//
//    for (int i = 1; i < MAXN; ++i) {
//        for (int j = 1; j < MAXN; ++j) {
//            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i][j];
//        }
//    }
//
//}
LL a[MAXN],b[MAXN];
void init(){
    memset(a,0, sizeof(a));
    memset(b,0, sizeof(b));
}

void update(LL num,LL A[]){
    LL r,q;
    r = num/2016;
    q = num%2016;

    for (int i = 0; i < 2016; ++i) {
        A[i] = r;
    }

    for (int i = 1; i <= q; ++i) {
        A[i]++;
    }
}

int main(){
    LL n,m;

    while (~scanf("%lld%lld",&n,&m)){
        init();
        update(n,a);
        update(m,b);
        LL ans = 0;

        for (int i = 0; i < 2016; ++i) {
            for (int j = 0; j < 2016; ++j) {
                if ((i*j)%2016 == 0){
                    ans += a[i]*b[j];
                }
            }
        }

        printf("%lld\n",ans);
    }
}