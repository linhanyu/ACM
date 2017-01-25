//
// Created by Henry on 16/11/2.
//

#include <cstdio>
#include <memory.h>

using namespace std;

const int MAXN = 7;

double pro[1<<MAXN][1<<MAXN];
double dp[MAXN+1][1<<MAXN];
int n;

int main(){


    while (~scanf("%d",&n) && ~n){
        for (int i = 0; i < (1<<n); ++i) {
            for (int j = 0; j < (1<<n); ++j) {
                scanf("%lf",&pro[i][j]);
            }
        }

        memset(dp,0, sizeof(dp));

        for(int i = 0; i < (1<<n); i++){
            //1表示还在
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            //i轮比赛
            for (int j = 0; j < (1 << n); ++j) {
                for (int k = 0; k < (1 << n); ++k) {
                    if (((j >> (i-1)) ^ 1) == (k>>(i-1)) ){
                        //奇偶性不同
                        dp[i][j] += dp[i-1][j] * dp[i-1][k] * pro[j][k];
                    }
                }
            }
        }

        int index = 0;

        for (int i = 1; i < (1 << n); ++i) {
            if (dp[n][index] < dp[n][i]) index = i;

        }

        printf("%d\n",index+1);

    }
}