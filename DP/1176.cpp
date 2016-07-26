//
// Created by Henry on 16/7/22.
//

#include <cstdio>
#include <memory>
#include <algorithm>

using namespace std;

#define NUM_1 100001
#define NUM_2 11
int main(){
    int n,t,x,max_t,Max;
    int cake[NUM_1][NUM_2];
    int dp[NUM_2];
    int dp_tmp[NUM_2];

    while(scanf("%d",&n)!=EOF && n){
        memset(cake,0, sizeof(cake));
        memset(dp,0, sizeof(dp));
        max_t = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d",&x,&t);
            cake[t][x] ++;
            max_t = max (max_t,t);
        }

        dp[4] = cake[1][4];
        dp[5] = cake[1][5];
        dp[6] = cake[1][6];

        Max = max(dp[4],max(dp[5],dp[6]));
        for (int i = 2; i <= max_t; ++i) {
            for (int j = 0; j < NUM_2 ; ++j) {
                dp_tmp[j] = dp[j] + cake[i][j];

                if (j>0){
                    dp_tmp[j] = max(dp_tmp[j],dp[j-1] + cake[i][j]);
                }

                if (j< NUM_2 -1){
                    dp_tmp[j] = max(dp_tmp[j],dp[j+1] + cake[i][j]);
                }

                Max = max(Max,dp_tmp[j]);
            }
            memcpy(dp,dp_tmp, sizeof(dp));
        }

        printf("%d\n",Max);

    }
}