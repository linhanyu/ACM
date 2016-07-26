//
// Created by Henry on 16/7/22.
//
#include <cstdio>
#include <algorithm>

#define NUM_1 13
#define NUM_2 1022
#define INF 0x7FFFFFF
using namespace std;

int need[NUM_1];
int dp[NUM_1][NUM_2];


int main(){
    int mouth,hir,sal,fir,tol;

    while(scanf("%d",&mouth)!=EOF && mouth){
        scanf("%d %d %d",&hir,&sal,&fir);
        tol = 0;
        for (int i = 0; i < mouth ; ++i) {
            scanf("%d",&need[i]);
            if (tol<need[i]) tol = need[i];
        }

        if(tol==0)
        {
            printf("0\n");
            continue;
        }

        for (int i = need[0]; i <= tol; ++i) {
            dp[0][i] = (hir+sal)*i;
        }

        for (int i = 1; i <= mouth ; ++i) {
            for (int j = need[i]; j <= tol; ++j) {
                if (need[i-1] > j) dp[i][j] = dp[i-1][need[i-1]] + sal * j + (need[i-1] - j) * fir;
                else dp[i][j] = dp[i-1][need[i-1]] + sal * j + (j - need[i-1]) * hir;
                //前一天需要的人比第二天雇j人多时,第二天cost为前一天所需的人数的最小花费加j人的薪水加开人的花费
                for (int k = need[i-1] + 1; k <= tol ; ++k) {
                    //遍历前一天租need~tol人的情况.此时j为这天租的人
                    if (j > k ) dp[i][j] = min(dp[i][j],dp[i-1][k] + sal * j + (j-k) * hir);
                    else dp[i][j] = min(dp[i][j],dp[i-1][k] + sal * j + (k-j) * fir);
                }
            }
        }

        int ans = INF;
        for (int i = need[mouth-1]; i <= tol ; ++i) {
            ans = min(ans,dp[mouth-1][i]);
        }
        printf("%d\n",ans);
    }

}

