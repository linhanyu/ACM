//
// Created by Henry on 16/7/22.
//

#include <algorithm>
#include <memory>

#define NUM 10001

using namespace std;

void zero_one_pack(double A[],int cost,double weight,int room){
    for (int i = room; i >=cost ; --i) {
        A[i] = max(A[i],1-(1-A[i-cost]) * (1-weight));
    }
}

int main(){
    int n,m,c;
    double w;
    double dp[NUM];
    while (scanf("%d %d",&n,&m)!=EOF && n + m){
        memset(dp,0, sizeof(dp));

        while(m--){
            scanf("%d %lf",&c,&w);
            zero_one_pack(dp,c,w,n);
        }

        printf("%.1lf%%\n",dp[n] * 100);
    }
}