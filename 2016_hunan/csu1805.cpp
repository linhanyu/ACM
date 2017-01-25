//
// Created by Henry on 17/1/16.
//

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MOD = 1000000007;


LL fac(LL n){
    LL ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = (ans*i)%MOD;
    }
    return ans;
}

int main(){
    LL a,b,c;
    while (~scanf("%lld%lld%lld",&a,&b,&c)){
        if (a > c) swap(a,c);

        printf("%lld\n",(fac(3*a)*(c-a))%MOD);

    }
}