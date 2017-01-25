//
// Created by Henry on 16/9/14.
//

#include <memory>
#include <iostream>
#include <cstdio>

#define MAXN 36

using namespace std;

int n;


long long solve(int n){
    long long dp[MAXN][MAXN];

    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = dp[i-1][i];
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return 2*dp[n][n];
}


long long ans[] = {2,
                   4,
                   10,
                   28,
                   84,
                   264,
                   858,
                   2860,
                   9724,
                   33592,
                   117572,
                   416024,
                   1485800,
                   5348880,
                   19389690,
                   70715340,
                   259289580,
                   955277400,
                   3534526380,
                   13128240840,
                   48932534040,
                   182965127280,
                   686119227300,
                   2579808294648,
                   9723892802904,
                   36734706144304,
                   139067101832008,
                   527495903500720,
                   2004484433302736,
                   7629973004184608,
                   29089272078453818,
                   111068129754096396,
                   424672260824486220,
                   1625888084299461528,
                   6232570989814602524,};

int main(){
//    for (int i = 1; i <= 35 ; ++i) {
//        printf("%lld,\n",solve(i) );
//
//    }

    int counter=1;
    while(cin>>n && n!=-1){
        printf("%d %d %lld\n",counter++,n,ans[n-1]);
    }
}