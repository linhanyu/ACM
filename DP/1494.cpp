//
// Created by Henry on 16/7/29.
//

#include <cstdio>
#include <algorithm>

#define NUM 105
#define INF 1<<30
#define MAXPOW 14
using namespace std;


int DP(int (*dp)[MAXPOW+1],int a[],int b[],int size,int n){

    dp[0][0] = 0;
    int q,w,e;               //不用加速器
    for( int i = 1; i <= size; i ++ )
    {
        for( int j = 0; j <= 14; j ++ )
        {
            q = w = e = INF;
            if( j >= 1 && dp[i-1][j-1] != -1 )   //不用加速器
                q = dp[i-1][j-1] + a[i%n];

            if( j == 10 && dp[i-1][14] != -1 )	//能量为14时不用加速器
                w = dp[i-1][14] + a[i%n];

            if( j < 10 && dp[i-1][j+5] != -1 )  //用加速器
                e = dp[i-1][j+5] + b[i%n];

            int Min = min(min(q,w),e);
            if( Min != INF )
                dp[i][j] = Min;
        }
    }
//    memset(dp,-1, sizeof(dp));
//    dp[0][0] = 0;
//    for (int i = 1; i <= size ; ++i) {
//        for (int j = 0; j <= MAXPOW; ++j) {
//            int act=INF,nact=INF,fact=INF;
//
//            if (j>=1 && dp[i-1][j-1]!=-1){
//                //不加速
//                act = speed[i%l] + dp[i-1][j-1];
//            }
//
//            if (j == 10 && dp[i-1][14] != -1){
//                //能量满了,不加速
//                fact = speed[i%l] + dp[i-1][14];
//            }
//
//            if (j <= 9 && dp[i-1][j+5] != -1){
//                //加速
//                nact = n2o[i%l] + dp[i-1][j+5];
//            }
//            int Min = min(min(nact,fact),act);
//            dp[i][j] = Min == INF ?-1:Min ;
//        }
//    }

    int ans = INF;
    for (int i = 0; i <= MAXPOW ; ++i) {
        if (dp[size][i] != -1)
        ans = min(dp[size][i],ans);
    }

    return ans;
}

int main(){
    int l,n;
    int speed[NUM],n2o[NUM],dp[NUM*NUM][MAXPOW+1];
    while( scanf("%d%d",&l,&n) != EOF )
    {
        for( int i = 1; i <= l; i ++ )
        {
            scanf("%d",&speed[i%l]);
        }
        for( int i = 1; i <= l; i ++ )
        {
            scanf("%d",&n2o[i%l]);
        }
        memset(dp,-1, sizeof(dp));
        //防止丢失类型信息
        int ans = DP(dp,speed,n2o,l*n,l);
        printf("%d\n",ans);
    }
    return 0;
}