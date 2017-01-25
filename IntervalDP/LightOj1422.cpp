//
// Created by Henry on 16/11/10.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int dp[MAXN][MAXN];
int cloth[MAXN];
int n;
//[i][j]表示区间i~j
void solve(){

    for (int i = 0; i <= n; ++i) {
        for (int j = i; j  <= n ; ++j) {
            dp[i][j] = j - i + 1;
        }
    }

    for (int i = n - 1; i > 0; --i) {
        for (int j = i ; j <= n ; ++j) {
            dp[i][j] = dp[i+1][j] + 1;
            for (int k = i + 1; k <= j ; ++k) {
                if (cloth[k] == cloth[i]){
                    dp[i][j] = min(dp[i][j],dp[i+1][k-1] + dp[k][j]);
                }

            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);

    for (int cases = 1; cases <= t ; ++cases) {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&cloth[i]);
        }

        solve();

        printf("Case %d: %d\n", cases, dp[1][n]);
    }

}