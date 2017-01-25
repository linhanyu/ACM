//
// Created by Henry on 16/7/28.
//
#include <cstdio>
#include <algorithm>
#include <memory>

#define NUM 62

using namespace std;

int main(){
    int t;
    double dp[11][NUM],a[11];
    double map[7];
    int point[] = { 5, 12, 22, 29, 33, 38, 42, 46, 50 ,55};
    bool flag = false;
    scanf("%d",&t);
    while (t--){
        if (flag) puts("");
        memset(dp,0, sizeof(dp));
        memset(a,0, sizeof(a));
        for (int i = 1; i <= 6 ; ++i) {
            scanf("%lf",&map[i]);
            dp[1][i] = map[i];
        }


        for (int i = 2; i <= 10; ++i) {
            for (int j = 1; j < NUM ; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    if (j-k <= 0) break;
                    dp[i][j] += dp[i-1][j-k] * map[k];

                }
            }
        }
        for(int i=10;i>0;i--)     a[0]+=dp[i][5];  printf("5: %.1lf%%\n",a[0]*100);
        for(int i=10;i>0;i--)     a[1]+=dp[i][12]; printf("12: %.1lf%%\n",a[1]*100);
        for(int i=10;i>0;i--)     a[2]+=dp[i][22]; printf("22: %.1lf%%\n",a[2]*100);
        for(int i=10;i>0;i--)    a[3]+=dp[i][29]; printf("29: %.1lf%%\n",a[3]*100);
        for(int i=10;i>0;i--)     a[4]+=dp[i][33]; printf("33: %.1lf%%\n",a[4]*100);
        for(int i=10;i>0;i--)    a[5]+=dp[i][38]; printf("38: %.1lf%%\n",a[5]*100);
        for(int i=10;i>0;i--)    a[6]+=dp[i][42]; printf("42: %.1lf%%\n",a[6]*100);
        for(int i=10;i>0;i--)    a[7]+=dp[i][46]; printf("46: %.1lf%%\n",a[7]*100);
        for(int i=10;i>0;i--)    a[8]+=dp[i][50]; printf("50: %.1lf%%\n",a[8]*100);
        for(int i=10;i>0;i--)    a[9]+=dp[i][55]; printf("55: %.1lf%%\n",a[9]*100);
        flag = true;
    }
}
