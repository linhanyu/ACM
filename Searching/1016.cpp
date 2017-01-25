//
// Created by Henry on 16/8/24.
//

#include <cstdio>
#include <vector>
#define NUM 22

using namespace std;
bool su[50];
bool used[NUM];
int dp[NUM],n;

void init(){
    dp[1] = 1;
    memset(su,1, sizeof(su));
    memset(used,0, sizeof(used));

    for (int i = 2; i < 50; ++i) {
        if (su[i]){
            for (int j = i*2; j < 50; j+=i) {
                su[j] = false;
            }
        }
    }


}

void dfs(int pos){
    if (pos <= n) {
        for (int i = dp[pos-1] & 1 ? 2:3; i <= n; i+=2) {
            if (su[i+dp[pos-1]] && !used[i]){
                used[i] = true;
                dp[pos] = i;
                dfs(pos+1);
                used[i] = false;
            }
        }
    } else if (su[dp[1] + dp[n]]){
        printf("1");
        for (int i = 2; i <= n ; ++i) {
            printf(" %d",dp[i]);
        }
        puts("");
    }
}
int main(){
    init();
    int count = 0;
    while(scanf("%d",&n)!=EOF){
        printf("Case %d:\n",++count);
        dfs(2);
        puts("");
    }

//
//    memset(used,0, sizeof(used));
//    PrintSet(0,8);
}