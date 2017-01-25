//
// Created by Henry on 16/7/28.
//

//n条直线互不平行且无三线共点的最多交点数max=1+2+……(n-1)=n(n-1)/2,
//n最大为20,则第一维最大为190.
#include <memory>

#define NUM 21
#define ToPoints(a) ((a)*((a)-1)/2)

bool dp[NUM][ToPoints(NUM)];

void init(){
    memset(dp,0, sizeof(dp));
    for (int i = 1; i < NUM; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 2; i < NUM; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k = 0; k < ToPoints(NUM); ++k) {
                if (dp[j][k]){
                    dp[i][k+(i-j)*j] = 1;
                }
            }
        }
    }
}

int main(){
    int n;
    init();
    while (scanf("%d",&n)!=EOF){
        printf("0");
        for (int i = 1; i <= ToPoints(n); ++i) {
            if (dp[n][i]){
                printf(" %d",i);
            }
        }
        puts("");
    }
}