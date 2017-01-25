//
// Created by Henry on 16/8/25.
//
#include <cstdio>
#include <algorithm>

#define NUM1 11
#define NUM2 11
#define ABS(a) ( (a) < 0 ? (-a):(a))



using namespace std;

//int solve(int card[]){
//
//    memset(dp,1, sizeof(dp));
//
//    for (int i = 1; i < NUM1; ++i) {
//        dp[0][i] = 0;
//    }
//    for (int i = 1; i <= 9; ++i) {
//        //移动1~9次
//        for (int j = 1; j < NUM2; ++j) {
//            //以1~10为头
//            dp[i][j] = dp[i-1][j];
//            for (int k = 1; k < NUM2; ++k) {
//                //遍历整个卡堆
//                for (int l = 0; l <= i; ++l) {
//
//                    if (card[j] > card[k] && (ABS(j-k) + dp[i-l][j] + dp[l][k] < dp[i][j])){
//                        dp[i][j] = ABS(j-k) + dp[i-l][j] + dp[l][k];
//                    }
//                }
//            }
//        }
//    }
//
//    return dp[9][10];
//
//}

int main(){
    int dp[NUM1][NUM2];
    int cases,tmp;
    int cards[NUM1];
    scanf("%d",&cases);
    while(cases--){
        memset(dp,0, sizeof(dp));
        memset(cards,0, sizeof(cards));
        for (int i = 1; i <= 10; ++i) {
            scanf("%d",&tmp);
            cards[tmp] = i;
        }

        for (int len = 1; len <= 9 ; ++len) {
            for (int i = 1; i+len < NUM1; ++i) {
                dp[i][i+len] =  dp[i][i+len-1] + ABS(cards[i+len] - cards[i+len - 1]);
                for (int j = i+1; j < len+i; ++j) {
                    dp[i][i+len] = min(dp[i][i+len],dp[i][j-1] + dp[j][len+i-1] + ABS(cards[i+len] - cards[j - 1]));
                }
            }
        }

        printf("%d\n",dp[1][10]);


    }
}