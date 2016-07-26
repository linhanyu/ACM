//
// Created by Henry on 16/7/21.
//

#include <cmath>
#include <algorithm>
#include <memory>
using namespace std;
#define NUM 101
#define ABS(a) ((a)>0?(a):(-a))

int k,n;
int dp[NUM][NUM],map[NUM][NUM];


int dfs(int row,int col){
    if (dp[row][col]){
        return dp[row][col];
    }
    dp[row][col] = map[row][col];
    for (int i = 1; i <= k; ++i) {

        if(row + i  < n && map[row+i][col] > map[row][col]){
            dp[row][col] = max(dp[row][col],dfs(row+i,col) +map[row][col]);
        }

        if(row - i >= 0 && map[row-i][col] > map[row][col]){
            dp[row][col] = max(dp[row][col],dfs(row-i,col) +map[row][col]);
        }

        if(col - i >= 0 && map[row][col - i] > map[row][col]){
            dp[row][col] = max(dp[row][col],dfs(row,col-i) + map[row][col]);
        }

        if(col + i < n  && map[row][col + i] > map[row][col]){
            dp[row][col] = max(dp[row][col],dfs(row,col+i) + map[row][col]);
        }

    }

    return dp[row][col];
}

int main(){
    while(scanf("%d %d",&n,&k)!=EOF && n!=-1 && k!=-1){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d",&map[i][j]);
            }
        }
        memset(dp,0, sizeof(dp));
        printf("%d\n",dfs(0,0));

    }
}