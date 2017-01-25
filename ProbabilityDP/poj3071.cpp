//
// Created by Henry on 17/1/21.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAXN = 7;
const double INF = 1e10;

double pb[1<<MAXN|10 ][1<<MAXN|10],dp[8][1<<MAXN|10];
int n;

void init(){
    memset(dp,0, sizeof(dp));
}

//void solve(){
//    int statu = (1<<n)- 1;
//
//    for (; statu >0 ; --statu) {
//        for (int i = 0; i < n; ++i) {
//            int cur = 1<<i;
//
//            if (cur & statu){
//                statu ^= cur;
//                for (int j = 0; j < n; ++j) {
//                    int k = 1<<j;
//                    if (k & statu){
//                        dp[statu] += dp[statu|cur]*pb[j][i];
//                    }
//                }
//                statu ^= cur;
//            }
//        }
//    }
//}
//
//int dfs(int l,int r){
//    if (dp[l][r]) return dp[l][r];
//
//    double ans = 0;
//    int Maxi = -1;
//    for (int i = l+1; i < r ; ++i) {
//        int L = dfs(l,i);
//        int R = dfs(i+1,r);
//        if (pb[L][R] > ans){
//            ans = pb[L][R];
//            Maxi = ;
//        }
//    }
//    return Maxi;
//}

int main(){
     while (~scanf("%d",&n) && ~n){
        init();

        for (int i = 0; i < 1<<n; ++i) {
            for (int j = 0; j < 1<<n; ++j) {
                scanf("%lf",&pb[i][j]);
            }
        }

        for (int i = 0; i < 1<<n; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n ; ++i) {
            for (int j = 0; j < 1<<n ; ++j) {
                for (int k = 0; k < 1<<n ; ++k) {
                    if (((j>>(i-1)) ^ 1) == (k>>(i-1))){
                        dp[i][j] += dp[i-1][j] * dp[i-1][k] * pb[j][k];
                    }
                }
            }
        }

        int Max = 0;
        for (int i = 1; i < 1<<n ; ++i) {
            if (dp[n][i] > dp[n][Max]) Max = i;
        }

        printf("%d\n",Max+1);
    }

}