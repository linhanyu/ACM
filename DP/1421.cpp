//
// Created by Henry on 16/7/26.
//
#include <cstdio>
#include <memory>
#include <algorithm>


#define NUM 2001
#define MINU_POW(a,b) (((a)-(b))*((a)-(b)))
#define INF 0x7F

using namespace std;


int weight[NUM];
int dp[NUM][NUM];
int main(){
    int n,k;
    weight[0] = 0;
    //setinal
    while(scanf("%d %d",&n,&k)!=EOF){

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&weight[i]);
        }

        sort(weight + 1,weight + n + 1);
        //排序后,最近的两个玩意儿,必然毗邻.
        dp[0][0] = 0;
        for (int i = 1; i <= n ; ++i) {
            //遍历n件物品
            dp[i][0] = 0;
            for (int j = 1; j <= i/2 ; ++j) {
                //抓i/2对

                if((i-1)/2 >= j) {
                    //
                    dp[i][j] = min(dp[i - 2][j - 1] + MINU_POW(weight[i], weight[i - 1]), dp[i - 1][j]);
                    //前两种抓一对,或者该种东西不抓,前面抓j对
                } else{
                    //前一种相应情况不存在,直接抓
                    dp[i][j] = dp[i - 2][j - 1] + MINU_POW(weight[i], weight[i - 1]);
                }
            }
        }

        printf("%d\n",dp[n][k]);

    }
}