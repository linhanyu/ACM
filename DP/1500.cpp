//
// Created by Henry on 16/7/29.
//

#include <cstdio>
#include <algorithm>

#define NUM 5010
#define INC 8
#define BADNESS(a,b) (((a)-(b))*((a)-(b)))

using namespace std;


struct CMP{
    bool operator() (const int & a,const int & b)const{
        return a>b;
    }
}cmp;
long set[NUM];
long dp[1010][NUM];
int main(){
    int t,k,n;
//    long dp[500][500];
//
//long set[NUM];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&k,&n);
        for (int i = n; i >= 1; --i) {
            scanf("%ld",&set[i]);

        }
        k+=8;
        //只有一个人的时候.set是0~n-1筷子


        for (int i = 1; i <= k; ++i) {
            //2~k个人
            int j = i*3;
            dp[i][j] = dp[i-1][j-2] + BADNESS(set[j],set[j-1]);
            j++;

            for (; j <= n; ++j) {
                //第3*(i+1)个筷子开始
                dp[i][j] = min(dp[i][j-1],BADNESS(set[j],set[j-1]) + dp[i-1][j-2]);
            }
        }

        printf("%ld\n",dp[k][n]);


    }
}
