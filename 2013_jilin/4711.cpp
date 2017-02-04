//
// Created by Henry on 17/1/31.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000 + 10;
const int MAXM = 100 + 10;
const double EPS = 1e-10;

int n,m,w;

int wCondition[MAXN];
double cPro[MAXM][MAXN];
double wPro[MAXM][MAXM];
double dp[MAXN][MAXM];


double dfs(int d,int c){
    if (d == n) return 1.0;

    if (dp[d][c] > 0) return dp[d][c];

    int w = wCondition[d];

    double ans = 0;
    int x = 0;
    for (int i = 0; i < m; ++i) {
        //d天从c出发结束旅程的概率
        double tmp = dfs(d+1,i)*cPro[c][i]*wPro[d][w];
        if (tmp > ans){
            ans = tmp;
            x = i;
        }
    }

    return dp[d][c] = ans;
}

void init(){
    memset(dp,0, sizeof(dp));
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d%d",&n,&m,&w);

        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&wCondition[i]);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%lf",&cPro[i][j]);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf("%lf",&wPro[i][j]);
            }
        }

        dfs(0,0);

        for (int i = 1; i <= n; ++i) {
            int c = 0;
            for (int j = 1;j < m; ++j) {
                if (dp[i][c] < dp[i][j]){
                    c = j;
                }
            }
            printf("%d%c",c,i == n ? '\n':' ');
        }
    }
}