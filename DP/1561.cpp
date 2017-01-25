//
// Created by Henry on 16/8/5.
//

#include <cstdio>

#define NUM 20

typedef long long Long;

Long dp[NUM][1<<NUM];


void solve(int n,Long (*rec)[]){
    int upperBound = 1<<n;
    for (int i = 0; i < n; ++i) {
        //从第一行到最后一行
        dp[i][0] = 0;
        for (int j = 0; j < upperBound; ++j) {
            for (int k = 0; k < n; ++k) {
                //扫一遍状态
                int cur = j & (1<<k);
                if (cur){
                    //如果取cur这个数
                    dp[i][j] += dp[i-1][j ^ cur] + rec[i][k];
                } else{
                    dp[i][j] += dp[i-1][j ^ cur] ;
                }
            }
        }
    }
}
int main(){
    int n;
    Long rec[NUM][NUM];
    while (scanf("%d",&n)!=EOF){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%lld",&rec[i][j]);
            }
        }



    }
}