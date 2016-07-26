//
// Created by Henry on 16/7/24.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#define NUM 35

using namespace std;

typedef __int64 Int_64;

Int_64 dp[NUM][NUM];
int map[NUM][NUM];

Int_64 n;
Int_64 dfs(int row,int col) {
    if (dp[row][col] != -1){
        return dp[row][col];
    }

    if (row == n && col == n){
        return 1;
    }

    if (map[row][col] == 0){
        return dp[row][col] = 0;
    }

    Int_64 sum = 0;

    if (row + map[row][col] <= n){
        sum += dfs(row + map[row][col],col);
    }

    if (col + map[row][col] <= n){
        sum += dfs(row,col + map[row][col]) ;
    }

    dp[row][col] = sum;
    return sum;
}

int main()
{
    char tmp;
    while(cin>>n)
    {
        if(n==-1)
            break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>tmp;
                map[i][j] = tmp-'0';
                dp[i][j]=-1;
            }
        }
        //memset(dp,-1,sizeof(dp));
        printf("%I64d\n",dfs(1,1));
    }
    return 0;
}
