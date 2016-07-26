//
// Created by Henry on 16/7/21.
//
#include <algorithm>
#include <iostream>

#define INF 0x3f3f3f3f
#define NUM 10011
using namespace std;



int main(){
    int t,n,c,w,room_begin,room_end;
    int dp[NUM];
    scanf("%d",&t);
    while (t--){
        cin>>room_begin>>room_end;
        room_end -= room_begin;
        memset(dp,INF,sizeof(dp));


        cin>>n;
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            cin>>w>>c;
            for (int i = c; i <= room_end; ++i) {
                dp[i] = min(dp[i-c] + w,dp[i]);
            }
        }

        if (dp[room_end] == INF){
            printf("This is impossible.\n");

        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[room_end]);
        }

//        memset(f,INF,sizeof(f));
//        V=h-e;
//        cin>>n;
//        f[0] = 0;
//        for(i = 0;i < n; i ++)
//        {
//            cin>>w>>c;
//            for(j = c; j <= V; j ++)
//                f[j]=min(f[j],f[j - c ]+w );
//        }
//
//        if(f[V]!=INF)
//            printf("The minimum amount of money in the piggy-bank is %d.\n",f[V]);
//        else
//            printf("This is impossible.\n");
    }
}
