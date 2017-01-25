//
// Created by Henry on 16/11/12.
//
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 1;
const int INF =  1<<27  ;
int sum[MAXN];
int A[MAXN];
int dp[MAXN][MAXN];

int n;

void solve(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dp[i][j]=INF;
    for(int l=1;l<=n-1;l++){
        for(int i=1;i<=n-l;i++){
            int j=i+l;
            //dp[i][j]=min(dp[i][j],dp[i+1][j]+sum[j]-sum[i]);
            for(int k=i;k<=j;k++)
                dp[i][j]=min(dp[i][j],A[i]*(k-i)+(k-i+1)*(sum[j]-sum[k])+dp[i+1][k]+dp[k+1][j]);
        }
    }

//    memset(dp,0, sizeof(dp));
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = i+1; j <= n ; ++j) {
//           dp[i][j] = INF;
//        }
//    }
//
//    for (int len = 1; len <= n-1 ; ++len) {
//        for (int i = 1; i <= n-1 ; ++i) {
//            int j = i+len;
//            for (int k = i; k <= j ; ++k) {
//                dp[i][j] = min(dp[i][j],A[i]*(k-i) + (k-i+1)*(sum[j] - sum[k]) + dp[i+1][k] + dp[k+1][j]);
//            }
//        }
//    }
}

int main(){
    int t;
    scanf("%d",&t);
    sum[0] = A[0];

    for(int cases = 1; cases <= t ;cases++){
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&A[i]);
            sum[i] = sum[i-1] + A[i];
        }

        solve();

        printf("Case #%d: %d\n",cases,dp[1][n]);

    }

}
