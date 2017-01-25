//
// Created by Henry on 16/8/28.
//
#include <memory>
#include <iostream>
#include <algorithm>
#include <cstdio>
#define NUM1 110
#define NUM2 2010

using namespace std;

void zeroOneBagBitPossible(int cost,int room, bool dp[]){
    for (int i = room; i >= cost ; --i) {
        dp[i] |= dp[i-cost];
    }
}

void zeroOneBagBitNegtive(int cost,int room, bool dp[]){
    for (int i = 0; i <= room-cost; ++i) {
        dp[i] |= dp[i+cost];
    }
}

int weight[NUM1];
bool dp[NUM2];

int main(){
    int cases,n,m,room,total;

    scanf("%d",&cases);

    while (cases--){
        memset(dp+1,0, sizeof(dp));
        dp[0] = true;
        scanf("%d",&n);
        total = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d",&weight[i]);
            total += weight[i];
            zeroOneBagBitPossible(weight[i],total,dp);
        }


        for (int i = 0; i < n; ++i) {
            zeroOneBagBitNegtive(weight[i],total,dp);
        }

        scanf("%d",&m);
        while (m--){

            scanf("%d",&room);
            if (dp[room]){
                puts("YES");
            } else{
                puts("NO");
            }
        }
    }
}
