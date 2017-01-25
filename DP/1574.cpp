//
// Created by Henry on 16/8/8.
//

#include <cstdio>
#include <algorithm>

#define NUM 20020
#define INF 0x7FFFFF
#define X 10000
using namespace std;


int Max;
void zeroOneBag(int dp[],int room,int cost,int weight){
    if (cost > 0){
        for (int i = room ; i >= 0; --i) {
            dp[i+cost] = max(dp[i+cost],dp[i] + weight);
            Max = max(dp[i+cost],Max);
        }

    } else {
        for (int i = room ; i <= 20000; ++i) {
            dp[i+cost] = max(dp[i+cost], dp[i] + weight);
            Max = max(dp[i+cost], Max);
        }
    }
}

int main(){
    int t,n,c,w,r;
    int dp[NUM];
    scanf("%d",&t);
    while(t--){
        for(int i = 0; i <= 2*X; i++) dp[i] = -INF;
        dp[X] = 0;
        Max = -INF;
        scanf("%d",&n);
        while (n--){
            scanf("%d %d %d",&c,&r,&w);
            zeroOneBag(dp,r+X,c,w);
        }


        printf("%d\n",Max);
    }
}