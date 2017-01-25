//
// Created by Henry on 16/8/20.
//

#include <cstdio>
#include <iostream>
#include <algorithm>


#define NUM 10


using namespace std;

//typedef long long Long;


int Lis(int assist[],int seq[],int size){
    int Max = 0;
    for (int i = 1; i <= size ; ++i) {

        for (int k = 0; k <= i-1; ++k) {
            if (seq[i] > seq[k] &&  assist[k] + 1 >  assist[i]){
                assist[i] = assist[k] + 1;
                Max = max(Max,assist[i]);
            }
        }
    }
    return Max;
}


int main(){
    int n,tmp,ans;
    int A[NUM],dp[NUM];

    A[0] = -1,dp[0] = 0;

    while(scanf("%d",&n)!=EOF && n ){
        memset(dp,0, sizeof(dp));
        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&A[i]);
        }

        ans = Lis(dp,A,n);

        printf("%d\n",ans);
    }
}
