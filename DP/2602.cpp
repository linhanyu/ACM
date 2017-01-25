//
// Created by Henry on 16/8/12.
//

#include <cstdio>
#include <algorithm>
#include <memory>

#define NUM 1001

using namespace std;

void zeroOneBag(int dp[],int room,int weight,int cost){
    for (int i = room; i >= cost; --i) {
        dp[i] = max(dp[i],dp[i-cost] + weight);
    }
}

int main(){
    int dp[NUM],weight[NUM],room,n,t,cost;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&room);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&weight[i]);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d",&cost);
            zeroOneBag(dp,room,weight[i],cost);
        }
        int ans = -1;
        for (int i = 0; i <= room; ++i) {
            ans = max(dp[i],ans);
        }
        printf("%d\n",ans);
    }
}
