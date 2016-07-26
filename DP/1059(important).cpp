//
// Created by Henry on 16/7/19.
//

#include<cstdio>
#include <memory>
#include <algorithm>

using namespace std;

#define NUM 120002

int marbles[6] ;
int dp[NUM];
bool flag = false;


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

int main(){
    int count=1,flg,num_sum,sum,pack_room;
    while (scanf("%d",&marbles[0])!=EOF){
        for (int i = 1; i < 6; ++i) {
            scanf("%d",&marbles[i]);
        }

        //全是0则退出
        flg = true;
        for (int j = 0; j < 6; ++j) {
            if (marbles[j]){
                flg  = false;
            }
        }
        if (flg) break;

        sum=0,num_sum=0;
        for (int i = 0; i < 6; ++i) {
            sum += marbles[i] * (i+1);
        }
        if (sum & 1){
            //总价值为奇数,分不了
            printf("Collection #%d:\nCan't be divided.\n\n",count++);
            continue;
        }

        pack_room = sum>>1;
        //总价值的一半
        memset(dp,0, sizeof(dp));
        for (int i = 1; i <= 6; ++i) {
            mix_pack(i,i,marbles[i-1],pack_room,dp);
        }

        if (dp[pack_room] == pack_room){
            printf("Collection #%d:\nCan be divided.\n\n",count++);
        } else{
            printf("Collection #%d:\nCan't be divided.\n\n",count++);
        }


    }
}