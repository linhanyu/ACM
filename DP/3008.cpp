//
// Created by twinklekuang on 16/4/7.
//#include <cstdio>
//#include <memory>
//#include <algorithm>
//
//#define NUM 105
//#define BLOOD 100
//
//using namespace std;
//
//struct skill{
//    int cost;
//    int damege;
//
//};
//
//int main(){
//    skill sk[NUM];
//    sk[0].cost = 0;
//    sk[0].damege = 1;
//
//    int dp[NUM][NUM];
//    //i:the attack time j:the magic remain dp[i][j]:after ith atttack ,remain j magic,the maxium damage
//    int n,t,q,temp,Max,i,tmp2;
//
//    bool  defeted;
//    while(scanf("%d %d %d",&n,&t,&q) && (n!=0 || t!=0 || q!=0)){
//        for (int i = 1 ; i <= n; ++i) {
//            scanf("%d %d",&sk[i].cost,&sk[i].damege);
//        }
//
//        memset(dp,0, sizeof(dp));
//        defeted = false;
//
//        for (i = 1;; ++i) {
//            for (int j = 0; j <= BLOOD && !defeted ; ++j) {
//                Max = 0;
//                for (int k = 0; k <= n ; ++k) {
//                    tmp2 = j+sk[k].cost;
//                    if (tmp2<=BLOOD) {
//                        temp = dp[i - 1][tmp2] + sk[k].damege;
//
//                        if (Max < temp){
//                            Max = temp;
//                            if (Max >= BLOOD) {
//                                defeted = true;
//                                break;
//                            }
//                        }
//                    }
//                }
//                dp[i][j] = Max;
//            }
//
//            for(int j=99;j>100-t;j--)
//                dp[i][100]=max(dp[i][j],dp[i][100]);
//            for(int j=100-t;j>=0;j--)
//                dp[i][j+t]=max(dp[i][j],dp[i][j+t]);
//
//
//            if (i*q >= BLOOD || defeted){
//                break;
//            }
//        }
//
//
//
//        if (defeted){
//            printf("%d\n",i);
//        } else{
//            printf("My god\n");
//
//        }
//
//
//    }
//
//
//}
//
