//
// Created by Henry on 16/11/20.
//
#include <cstdio>

typedef long long LL;

using namespace std;

LL k,n,m;

int main(){
    while (~scanf("%lld%lld%lld",&n,&m,&k)){
        k>>=1;
        LL ans = 0;
        for (LL i = 1; i <= n && k-i>0; ++i) {
            LL num = k-i;
            if(num <= m ){
                ans += (2*m-num+1)*num/2*(n-i+1);
            } else{
                ans += (1+m)*m/2*(n-i+1);
            }
        }

        printf("%lld\n",ans);
    }
}
