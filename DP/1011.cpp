//
// Created by twinklekuang on 16/4/8.
//

#include <iostream>
#include <queue>
#include <algorithm>

#define NUM 110



using namespace std;

struct NODE{
    int bugs;
    int possibility;


};
int dp[NUM][NUM];
int m,n,tmp_1,tmp_2;
NODE node[NUM];
bool Relation_After[NUM][NUM];
bool vis[NUM];

void dfs(int root){
    int cost = (node[root].bugs+19)/20;
    for (int i = cost; i <=m ; ++i) {
        dp[root][i] = node[root].possibility;
    }
    vis[root] = true;

    for (int i = 1; i <= n ; ++i) {
        if (Relation_After[root][i] && !vis[i]){
            dfs(i);
            for (int j=m;j>=cost;j--) {
                for (int k = 1; k <= j-cost; ++k) {
                    dp[root][j] = max(dp[root][j],dp[i][k]+dp[root][j-k]);
                }
            }
        }

    }

}

//int main(){
//
//
//    while(cin>>n>>m){
//        if (m ==-1 && n == -1){
//            break;
//        }
//
//
//        memset(dp,0, sizeof(dp));
//        memset(vis,0, sizeof(vis));
//        memset(Relation_After,0, sizeof(Relation_After));
//
//        for (int i = 1; i <= n; ++i) {
//            cin>>node[i].bugs>>node[i].possibility;
//        }
//
//        for (int i = 1; i < n; ++i) {
//            cin>>tmp_1>>tmp_2;
//            Relation_After[tmp_1][tmp_2] = Relation_After[tmp_2][tmp_1] = true;
//        }
//
//
//        if(m==0) {
//            printf("0\n");
//            continue;
//        }
//        dfs(1);
//        cout<<dp[1][m]<<endl;
//
//    }
//
//}