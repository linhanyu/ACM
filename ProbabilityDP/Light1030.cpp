//
// Created by Henry on 17/1/20.
//

#include <cstdio>
#include <memory.h>

const int MAXN = 100 + 10;

int cave[MAXN];
double dp[MAXN];

void init() {
    memset(dp,0, sizeof(dp));
}
int main(){
    int t,cases=0;
    scanf("%d",&t);
    while (t--){
        init();

        int n;
        scanf("%d",&n);

        for (int i = 1; i <= n; ++i) {
            scanf("%lf",&dp[i]);
        }


        for (int i = n-1; i >= 0 ; --i) {
            for (int j = 1; j <= 6 && i+j <= n ; ++j) {
                dp[i] += dp[i+j]/(n-i > 6 ? 6 : n-i);
            }

        }
        printf("Case %d: %.6lf\n",++cases,dp[1]);
    }
}