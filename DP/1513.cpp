//
// Created by Henry on 16/8/3.
//

#include <cstdio>
#include <algorithm>

#define NUM 5002

using namespace std;

int dp[2][NUM-1];
int main(){
    int n;
    char seq[NUM];
    while (scanf("%d",&n)!=EOF){
        scanf("%s",seq+1);

        for (int i = 0; i <= n; ++i) {
            dp[1][i] = dp[0][i] = 0;

        }
        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x,y;
                x=i&1;
                y=!x;
                if(seq[i] == seq[n-j+1]){
                    dp[x][j] = dp[y][j-1] + 1;
                } else{
                    dp[x][j] = max(dp[y][j],dp[x][j-1]);
                }
            }
        }

        printf("%d\n",n-dp[n&1][n]);
    }
}