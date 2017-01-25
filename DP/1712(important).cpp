//
// Created by Henry on 16/8/10.
//

#include <cstdio>
#include <memory>
#include <algorithm>

#define NUM 105

using namespace std;

//void zeroOneBag(int dp[],int room,int weight,int cost){
//    for (int i = cost; i <= room ; ++i) {
//        dp[i] = max(dp[i],dp[i-cost] + weight);
//    }
//}
void groupBag(int group[],int dp[],int Groupsize){
    for (int i = Groupsize; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i],dp[j] + group[i-j]);
        }
    }
}
int main(){
    int n,m;
    int map[NUM],dp[NUM];

    while(scanf("%d %d",&n,&m)!=EOF && (m || n) ){
        memset(dp,0, sizeof(dp));
        //强行压缩笑哈哈
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d",&map[j]);
            }

            groupBag(map,dp,m);

        }




        printf("%d\n",dp[m]);
    }
}