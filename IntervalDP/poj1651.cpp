//
// Created by Henry on 16/11/11.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 100 + 10;

int n;
int A[MAXN];
LL dp[MAXN][MAXN];

void solve(){
    //1~n

    memset(dp,0x3f, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        dp[i][i-1] = 0;
    }

    for(int i = 1; i <= n - 2;i++){
        for (int j = n - 1 ; j >= i + 1 ; --j) {
            //dp[j-i+1][j]
            for (int k = j-i+1; k <= j ; ++k) {
                dp[j-i+1][j] = min(dp[j-i+1][k-1] + dp[k+1][j] + A[k] * A[j-i] * A[j+1],dp[j-i+1][j]);
            }
        }
    }

    printf("%lld\n",dp[2][n-1]);
}

int main(){
    while (~scanf("%d",&n)){
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&A[i]);
        }

        solve();

    }
}