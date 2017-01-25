//
// Created by Henry on 16/8/12.
//

#include <cstdio>
#include <memory>
#define NUM 31


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{   int a[50];
    int n,m;
    int i,j;
    while(cin>>n>>m && (n||m))
    {
        memset(a,0,sizeof(a));
        a[1]=1;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(i+j<=n)
                    a[i+j]+=a[i];
        cout<<a[n]<<endl;
    }
    return 0;
}
//
//int dp[NUM][NUM];
//void init(){
//    for (int i = 1; i < NUM; ++i) {
//        dp[1][i] = 1;
//    }
//
//    for (int i = 2; i < NUM; ++i) {
//        //跳过2~30人
//        for (int j = 2; j < NUM; ++j) {
//            //队里有i~30人
//            dp[i][j] = dp[i-1][j];
//            for (int k = i; k < j; k+=i) {
//                if (j>k)
//                dp[i][j] += dp[k][j-k];
//            }
//        }
//    }
//}
//
//int main(){
//    int n,m;
//    init();
//    while(scanf("%d %d",&n,&m)!=EOF && (m||n)){
//        printf("%d\n",dp[m][n]);
//
//
//    }
//}