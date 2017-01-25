//
// Created by Henry on 16/12/18.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

typedef long long LL;

const int MAXN = 10000;
const LL INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

//LL a[MAXN];
//LL dp[MAXN][MAXN];
//
//void init(){
//    memset(dp,0, sizeof(dp));
//    memset(a,0, sizeof(a));
//}
LL shit[MAXN][MAXN];
int main(){

//    int n;
//
//    while (~scanf("%d",&n)){
//        init();
//
//        for (int i = 1; i <= n; ++i) {
//            scanf("%lld",&a[i]);
//        }
//
//
//        for (int i = 0; i < n ; ++i) {
//            //区间大小0~n-1
//            for (int j = n - i ; j > 0 ; --j) {
//                dp[j][j+i] = INF;
//                for (int k = j; k <= j+i; ++k) {
//                    dp[j][j+i] = min(dp[j][j+i],dp[j][k-1] + dp[k+1][j + i] + a[k] + a[j-1] + a[j+i+1]);
//                }
//            }
//        }
//
//        printf("%lld\n",dp[1][n]);
//
//    }
}