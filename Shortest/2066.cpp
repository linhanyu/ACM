//
// Created by Henry on 16/4/26.
//

//#include <cstdio>
//#include <algorithm>
//#include <memory>
//#include <queue>
//
//#define NUM 1001
//#define INF 0x7F
//#define INF2 0x7FFFFF
//using namespace std;
//
//int dis[NUM];
//struct cmp{
//    bool operator() (int a,int b){
//        return dis[a] > dis[b];
//    }
//};
//
//int main(){
//    int t,s,d,time,a,b,item,upb,Min;
//    int Relation[NUM][NUM];
//    int wt[NUM];
//    bool explored[NUM];
//
//    priority_queue<int,vector<int >,cmp>  Q;
//
//    while (scanf("%d%d%d",&t,&s,&d)!=EOF){
//        memset(Relation,-1, sizeof(Relation));
//        memset(explored,0, sizeof(explored));
//        memset(dis,INF, sizeof(dis));
//        upb = 0;
//
//        for (int i = 0; i < t; ++i) {
//            scanf("%d%d%d",&a,&b,&time);
//            if (Relation[a][b]<0||Relation[b][a] > time){
//                Relation[b][a] = Relation[a][b] = time;
//                upb = max(a,max(upb,b));
//            }
//
//        }
//
//        for (int i = 0; i < s; ++i) {
//            scanf("%d",&a);
//            Relation[0][a] = Relation[a][0] = 0;
//        }
//
//        for (int i = 0; i < d; ++i) {
//            scanf("%d",&wt[i]);
//        }
//
//        Q.push(0);
//        explored[0] = true;
//        dis[0] = 0;
//
//        while(!Q.empty()){
//            item = Q.top();
//            explored[item] = true;
//            Q.pop();
//            while(!Q.empty() && item == Q.top())Q.pop();
//
//            for (int i = 0; i <= upb; ++i) {
//                if (!explored[i] && Relation[item][i] >=0){
//                    a = dis[item] + Relation[item][i];
//                    if (dis[i] > a){
//                        dis[i] = a;
//                    }
//                    Q.push(i);
//                }
//            }
//        }
//        Min = INF2;
//        for (int i = 0; i < d; ++i) {
//            Min = min(dis[wt[i]],Min);
//        }
//        printf("%d\n",Min);
//
//    }
////    int t,s,d,a,b,time,Min,upbound;
////    int dp[NUM][NUM];
////    int wt[NUM],st[NUM];
////    while (scanf("%d%d%d",&t,&s,&d)!=EOF){
////        upbound=0;
////
////        for(int i=1;i<NUM;i++)
////            for(int j=1;j<NUM;j++)
////                if(i==j) dp[i][j]=0;
////                else    dp[i][j]=INF;
////
////        for (int i = 1; i <= t; ++i) {
////            scanf("%d%d%d",&a,&b,&time);
////            if(dp[a][b]>time)
////                dp[a][b]=dp[b][a]=time;
////            upbound = max(a,max(b,upbound));
////        }
////        for (int i = 1; i <= s; ++i) {
////            scanf("%d",&st[i]);
////
////
////        }
////        for (int i = 1; i <= d; ++i) {
////            scanf("%d",&wt[i]);
////        }
////
////        for (int i = 1; i <= upbound;++i) {
////            for (int j = 1; j <= upbound; ++j) {
////                for (int k = 1; k <= upbound; ++k) {
////                    dp[j][k] = min(dp[j][i] + dp[i][k],dp[j][k]);
////                }
////            }
////        }
////        Min = INF;
////        for (int i = 1; i <= d; ++i) {
////            for (int j = 1; j <= s; ++j) {
////                Min = min(Min,dp[st[j]][wt[i]]);
////            }
////        }
////
////        printf("%d\n",Min);
////    }
//}