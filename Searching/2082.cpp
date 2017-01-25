//
// Created by Henry on 16/9/14.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void zero_one_pack(int cost,int weight,int room,int ar[]){
    for (int i = room; i >= cost; --i) {
        ar[i] = max(ar[i-cost] + weight,ar[i]);
        //dp[i][j] = dp[i-1][j-cost]+weight,dp[i-1][j])装/不装
        //通过滚动数组优化,减为1维.
        //对于0/1背包,为了保证dp[i][j]的状态是由dp[i-1]装或不装一个而得来的(因为物品数量有限),遂从后往前
        //dp.这样,可以保证dp[i]都是从dp[i-1]得来的
    }
}

void complete_pack(int cost,int weight,int room,int ar[]){
    for (int i = cost; i <= room ; ++i) {
        ar[i] = max(ar[i-cost] + weight,ar[i]);
        //看似和zero_one_pack一样,其实不同.
        //原方程为f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v}
        //经过滚动数组优化成一维.因为物品数量无限,所以i应从cost往上递增
        //在考虑“加选一件第i种物品”这种策略时，却正需要一个可能已选入第i种物品的
        //子结果f[i][v-c[i]]，所以就可以并且必须采用v=0..V的顺序循环

    }
}

void mix_pack(int cost,int weight,int amount,int room,int ar[]){
    int tmp = cost * amount;
    if (tmp >= room){
        complete_pack(cost,weight,room,ar);
    } else{
        for (int i = 1 ; i < amount; i<<=1) {
            zero_one_pack(cost*i,weight*i,room,ar);
            amount -= i;
        }
        zero_one_pack(amount * cost,amount * weight ,room,ar);
    }
}

const int MAXN = 26;
const int ROOM = 50;
int dp[ROOM + 10];
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        memset(dp,0, sizeof(dp));
        for (int i = 1; i <= MAXN; ++i) {
            int tmp;
            cin>>tmp;
            mix_pack(i,1,tmp,ROOM,dp);
        }

        long long ans=0;
        for (int i = 1; i <= ROOM; ++i) {
            ans += dp[i];
        }
        cout<<ans<<endl;
    }
}