//
// Created by twinklekuang on 16/4/9.
//

//#include <iostream>
//
//#include <cmath>
//
//#include <algorithm>
//#include <memory>
//
//#define NUM 205
//#define INF 9999
//
//
//using namespace std;
//
//int main(){
//    int n,k;
//    int Case[NUM][NUM];
//    int dis[NUM];
//    int dp[NUM][NUM];
//    int count = 0;
//
//    while (cin>>n>>k){
//        if (n==0 || k == 0){
//            break;
//        }
//
//        memset(dis,0, sizeof(dis));
//        memset(Case,0, sizeof(Case));
//        memset(dp,INF, sizeof(dp));
//
//        for (int i = 1; i <= n ; ++i) {
//            cin>>dis[i];
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = i; j <= n ; ++j) {
//                for (int k = i; k <= j; ++k) {
//                    Case[i][j] += abs(dis[k]-dis[(i+j)/2]) ;
//                }
//            }
//
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            dp[1][i] = Case[1][i];
//
//        }
//
//        for (int i = 2; i <= k; ++i) {
//            for (int j = i; j <= n ; ++j) {
//                for (int l = i; l <= j; ++l) {
//                    dp[i][j] = min(dp[i][j],dp[i-1][l-1] + Case[l][j]);
//                }
//            }
//        }
//        printf("Chain %d\nTotal distance sum = %d\n\n",++count,dp[k][n]);
//    }
//}