//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 1000 + 10;
const int MAXG = 110;

int dp[MAXG][MAXN];
int weight[MAXN],cost[MAXN],room[MAXG];
int g,n;

void pack(int dp[],int room,int weight,int cost){
    for (int i = room; i >= weight ; --i) {
        dp[i]= max(dp[i],dp[i-weight] + cost);
    }
}


int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        memset(dp,0, sizeof(dp));

        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&cost[i],&weight[i]);
        }

        scanf("%d",&g);
        for (int i = 0; i < g; ++i) {
            scanf("%d",&room[i]);
            for (int j = 0; j < n; ++j)pack(dp[i],room[i],weight[j],cost[j]);
        }


        long long sum = 0;
        while (g--) sum += dp[g][room[g]];

        printf("%lld\n",sum);
    }
}