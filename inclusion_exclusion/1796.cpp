//
// Created by Henry on 16/10/25.
//

#include <cstdio>
#include <algorithm>

#define LowBit(x) (x&(-x))

typedef long long LL;

const int MAXN = 10;

using namespace std;

int n,m;
int num[MAXN];
LL dp[1<<MAXN];
bool counter[1<<MAXN];

LL gcd_(LL a,LL b){
    return b ? gcd_(b,a%b): a;
}

LL gcd(LL a,LL b){
    if (a < b) swap(a,b);
    return gcd_(a,b);
}

LL LCM(LL a,LL b){
    return a/gcd(a,b)*b;
}

int Bitnum(int bit){
    int res = 0;
    while (bit){
        res++;
        bit >>=1;
    }
    return res;
}

void solve(){
    int end = (1<<m) - 1;
    int res = 0;

    dp[0] = 1 ;
    counter[0] = 0;
    for (int i = 1; i <= end; ++i) {

        dp[i] = LCM(dp[i ^ LowBit(i)],num[Bitnum(LowBit(i))-1]);
        counter[i] = !counter[i ^ LowBit(i)];
//        for (int j = 0; j < m; ++j) {
//            int cur = 1<<j;
//            if (i & cur){
//                counter ++;
//                x = LCM(x,num[j]);
//            }
//        }

        res += (n-1)/(counter[i] ? dp[i]:-dp[i]);
    }

    printf("%d\n",res);
}

int main(){
    while (~scanf("%d %d",&n,&m)){
        bool flag = true;
        int cur = 0,tmp;
        for (int i = 0; i < m; ++i) {

            scanf("%d",&tmp);
            if (tmp && tmp < n){
                num[cur++] = tmp;
            }
        }

        m = cur;

        solve();


    }
}