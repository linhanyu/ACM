//
// Created by Henry on 16/7/22.
//

#include <cstdio>
#define NUM_1 1000000
#define NUM_2 4
int dp[NUM_2][NUM_1];
void init(){
    for (int i = 0; i < NUM_1; ++i) {
        dp[0][i] = i+1;
    }

    for (int i = 1; i < NUM_2; ++i) {
        dp[i][0] = dp[i-1][1];
    }

    for (int i = 1; i < NUM_2 ; ++i) {
        for (int j = 1; j < NUM_1; ++j) {
            dp[i][j] = dp[i - 1][dp[i][j - 1]];
        }
    }

    for (int i = 1; i <= 24; ++i) {
        dp[3][i] = dp[2][dp[3][i - 1]];
    }
}

int main(){
    init();
    int m,n;
    while(scanf("%d %d",&m,&n)){
        printf("%d\n",dp[m][n]);
    }
}