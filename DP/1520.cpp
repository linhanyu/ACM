//
// Created by Henry on 16/8/4.
//

#include <algorithm>
#include <cstdio>
#include <memory>
#include <vector>
#define NUM 6005

using namespace std;

int dp[2][NUM],val[NUM];
bool rt[NUM];
vector<int> rls[NUM];



void dfs(int root){

    dp[0][root] = 0;
    dp[1][root] = val[root];

    for (int i = 0; i < rls[root].size(); ++i) {
        dfs(rls[root][i]);
        dp[0][root] += max(dp[0][rls[root][i]],dp[1][rls[root][i]]);
        dp[1][root] += dp[0][rls[root][i]];
    }

}

int main(){
    int n,v,u;
    while (scanf("%d",&n)!=EOF) {

        memset(rt,true, sizeof(rt));

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&val[i]);
            rls[i].clear();
        }

        while(scanf("%d %d",&v,&u)!=EOF && (u||v)){
            rls[u].push_back(v);
            rt[v] = false;
        }

        int ans = 0;
        for (int i = 1; i <= n ; ++i) {
            if (rt[i]) {
                dfs(i);
                ans += max(dp[1][i], dp[0][i]);
            }
        }

        printf("%d\n",ans);


    }

}