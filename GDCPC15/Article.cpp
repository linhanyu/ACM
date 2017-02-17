//
// Created by Henry on 17/2/8.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
const double INF = 1e10;
int n,x;
double p;

double dp[MAXN],g[MAXN];

int main(){
    int t;
    scanf("%d",&t);
    g[0] = dp[0] = 0;

    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);
        scanf("%d%lf%d",&n,&p,&x);
        p = 1-p;
        for (int i = 1; i <= n  ; ++i) {
            g[i] = (g[i-1] + 1)/p;
            dp[i] = dp[i-1] + g[1] + x;

            for (int j = i-2; j >= 0; --j) {
                if (g[i-j] > dp[i]) break;
                dp[i] = min(dp[i],dp[j] + g[i-j] + x);
            }
        }
        printf("%.6lf\n",dp[n]);

    }
}