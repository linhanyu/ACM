//
// Created by Henry on 16/7/26.
//
#include <cstdio>
#include <memory>
#define NUM 101


void init( bool (*dp)[NUM]){
    for (int i = 1; i < NUM; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < NUM; ++i) {
        for (int j = 1; j < NUM; ++j) {
            if (j%i == 0){
                dp[i][j] = !dp[i-1][j];
            } else{
                dp[i][j] = dp[i-1][j];

            }
        }
    }
}

int main(){
    int t,n,count;
    bool dp[NUM][NUM];
    init(dp);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        count = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[n][i]){
                count++;
            }
        }

        printf("%d\n",count);
    }
}
