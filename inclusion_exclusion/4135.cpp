//
// Created by Henry on 16/10/25.
//

#include <cstdio>
#include <vector>
//#include <memory.h>
#define LowBit(x) (x&(-x))

typedef long long LL;

const int MAXN = 20;
//const int su[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

using namespace std;

LL a,b,n;

LL dp[1<<MAXN];
bool counter[1<<MAXN];

vector<int > factor;

void deconstruct(LL n){
    for (int i = 2; i*i<=n; ++i) {
        if (n%i == 0){
            factor.push_back(i);
            while (n%i == 0) n/=i;
        }
    }

    if (n>1) {
        factor.push_back(n);
    }
}

int bitLen(int bit){
    int res=0;
    while (bit){
        bit >>= 1;
        res++;
    }

    return res;
}

LL ie(LL num){
    int end = (1<<factor.size()) - 1;
    LL res = 0;

    dp[0] = 1;
    counter[0] = 0;

    for (int i = 1; i <= end ; ++i) {

        dp[i] = dp[i ^ LowBit(i)] * factor[bitLen(LowBit(i)) - 1];
        counter[i] = !counter[i ^ LowBit(i)];

        if (counter[i]){
            res += num/dp[i];
        } else{
            res -= num/dp[i];
        }

    }

    return res;

}

void solve(){
    factor.clear();

    deconstruct(n);

    LL up = b - ie(b);
    LL down = a - 1 - ie(a-1);

    printf("%lld\n",up-down);
}

//bool su[100];

int main() {
//    memset(su,1, sizeof(su));
//    su[1] = 0;
//    for (int i = 2; i < 100; ++i) {
//        if (su[i]){
//            for (int j = 2*i; j < 100; j += i) {
//                su[j] = false;
//            }
//
//        }
//    }
//
//    for (int i = 1; i < 100; ++i) {
//        if (su[i])
//        printf("%d,",i);
//    }
//}

    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ",i);
        scanf("%lld %lld %lld",&a,&b,&n);

        solve();
    }
}