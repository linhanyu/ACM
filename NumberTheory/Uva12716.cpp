//
// Created by Henry on 16/10/30.
//

#include <cstdio>
#include <memory.h>
#include <cmath>
const int MAXN = 30000000 + 5;

typedef long long LL;

LL n;

LL pais[MAXN];
LL gcd(LL a,LL b){
    return b ? gcd(b,a%b) : a;
}

void init(){
    memset(pais,0, sizeof(pais));

    for (int c = 1; c <= (MAXN>>1); ++c) {
        for (int a = (c<<1); a < MAXN ; a += c) {
            int b = a-c;

            if (c == (a^b)){
                pais[a]++;
            }
        }
    }

    for (int i = 2; i < MAXN; ++i) {
        pais[i] += pais[i-1];
    }

}

void solve(){
//    LL ans = 0;
//    for (LL i = 1; i <= n; ++i) {
//        for (LL j = 1; j <= i; ++j) {
//            if (gcd(i,j)  == (i^j)){
//                ans++;
//            }
//        }
//    }

}

int main(){
    int t;
    init();
    scanf("%d",&t);
    for (int i = 1; i <= t; ++i) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i,pais[n]);
    }
}