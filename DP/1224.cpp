//
// Created by twinklekuang on 16/4/9.
//

//#include <iostream>
//#include <cstdio>
//
//#include <algorithm>
//#include <memory>
//
//#define NUM 105
//#define INF 0x7FFFFFFF
//
//
//using namespace std;
//
//int dp[NUM],n,way[NUM];
//bool Relation[NUM][NUM];
//int item[NUM];
//
//void dfs(int root){
//    if (root == n+1){
//        return;
//    }
//
//    int Max=-INF,next = n+1;
//    bool flag= false;
//    for (int i = 1; i <= n+1; ++i) {
//        if (Relation[root][i]){
//            flag = true;
//            dfs(i);
//            if (Max<dp[i]){
//                Max = dp[i];
//                next = i;
//
//            }
//        }
//    }
//    if (flag) {
//        dp[root] = Max + item[root];
//        way[root] = next;
//    } else{
//        dp[root] = -INF;
//
//    }
//}
//
//int main(){
//    int t,m,tmp_1,tmp_2,k;
//    int flag= false;
//    cin>>t;
//    for (int z = 1; z <= t; ++z) {
//        if (flag){
//            printf("\n");
//        }
//        cin>>n;
//        memset(Relation, false, sizeof(Relation));
//        memset(dp, 0, sizeof(dp));
//
//        for (int i = 1; i <= n; ++i) {
//            cin>>item[i];
//        }
//        item[n+1] = item[1];
//
//        cin>>m;
//        for (int j = 0; j < m; ++j) {
//            cin>>tmp_1>>tmp_2;
//            Relation[tmp_1][tmp_2] = true;
//        }
//
//        dfs(1);
//        printf("CASE %d#\npoints : %d\ncircuit : ",z,dp[1]);
//        k=1;
//        while(k!=n+1){
//            printf("%d->",k);
//            k = way[k];
//        }
//        printf("1\n");
//        flag = true;
//    }
//
//}