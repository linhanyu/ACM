//
// Created by Henry on 16/7/27.
//

#include <cstdio>
#include <algorithm>

#define NUM 200002

using namespace std;

struct cmp{
    bool operator() (const int & a,const int & b) const {
        return a>b;
    }
}CMP;

int main(){
    int dp[NUM];
    int n,cost,sum,len,ans;

    while (scanf("%d",&n)!=EOF){
        //环形最长子列
        //空间换时间
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&dp[i],&cost);
            dp[i] -= cost;
            dp[i+n] = dp[i];
        }

        len = 0;
        sum = 0;
        ans = 0;

        for (int i = 0; i<n*2; ++i) {
            sum += dp[i];
            len++;

            if (sum<0){
                sum = 0;
                len = 0;
            }

            if (len > ans){
                ans = len;
            }

            if (len >= n){
                break;
            }
        }

        printf("%d\n",len>=n?len:ans);

    }
}
