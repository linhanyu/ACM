//
// Created by Henry on 16/8/5.
//

#include <cstdio>
#include <algorithm>
#include <memory>
#define NUM 15

typedef long long Long;
using namespace std;

//void build(){
//    Long tmpBit;
//    Long count;
//
//    for (Long l = 1; l <= 62 ; ++l) {
//        //n从1~62
//        for (Long k = 2; k <= 5 ; ++k) {
//            //range 2~5
//            count = 0;
//            for (Long i = 0; i < (1<<l); ++i) {
//
//                for (Long j = 1; j < NUM; ++j) {
//                    //扫一遍
//                    tmpBit = i&(1<<j);
//                    if (tmpBit){
//                        count++;
//                    }
//                }
//                if (l-count <= k){
//                    //这种状态合格,则撸一串
//                    dp[l][k]++;
//                }
//
//            }
//        }
//    }
//
//
//}

#define W 5

int main(){
    int n,k;
    Long dp[63][10][10];
    while (scanf("%d %d",&n,&k)!=EOF){
        memset(dp,0, sizeof(dp));
        dp[0][W][W] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = W-k; j <= W; ++j) {
                //偏移量为w
                for (int l = W; l <= W+k; ++l) {
                    dp[i+1][min(j+1,W)][l+1] += dp[i][j][l];
                    dp[i+1][j-1][max(l-1,W)] += dp[i][j][l];
                }
            }
        }

        Long ans = 0;
        for (int i = W-k; i <= W ; ++i) {
            for (int j = W; j <= W+k; ++j) {
                ans += dp[n][i][j];
            }
        }
        printf("%lld\n",ans);

    }
}