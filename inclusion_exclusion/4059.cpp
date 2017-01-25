//
// Created by Henry on 16/10/25.
//

#include <cstdio>
#include <vector>

#define LowBit(x) (x&(-x))
#define Pow4(a) (a*a*a*a)
typedef long long LL;

const int MAXN = 20;
const int MOD = 1000000007;
using namespace std;

LL n;

LL dp[1<<MAXN];
bool parity[1<<MAXN];

vector<LL > factor;

void deconstruct(LL num){
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0){
            factor.push_back(i);
            while (num % i == 0) num/=i;
        }
    }

    if (num>1){
        factor.push_back(num);
    }
}

int BitLen(int bit){
    int res=0;
    while(bit){
        bit >>= 1;
        res++;
    }
    return res;
}

void solve(){
    factor.clear();
    deconstruct(n);

    parity[0] = 0;
    dp[0] = 1;
    LL res = 1;

    for (int i = 1; i <= (1<<factor.size())-1 ; ++i) {
         
    }

    printf("%lld\n",res);

}


int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lld",&n);

        solve();
    }
}