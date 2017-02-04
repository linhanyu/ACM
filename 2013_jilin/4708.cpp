//
// Created by Henry on 17/1/30.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10;
const int INF = 0x3f3f3f3f;
int mp[MAXN][MAXN];
int n,step;

int dfs(int pos){
    if (pos >= n/2) return 0;


    int ans = -INF,s = 0;
    for (int i = 0; i <= n-2*pos-2; ++i) {
        int cost  = mp[i + pos][pos] + mp[n - pos - i - 1][n - pos - 1] + mp[pos][n - 1 - i - pos] + mp[n- pos - 1][i + pos];
        if (ans < cost){
            ans = cost;
            s = min(i,n-2*pos - i -1);
        } else if (ans == cost){
            s = min(s,min(i,n-2*pos - i -1));
        }

    }
    step += s;
    return dfs(pos+1) + ans;

}

int main(){

    while (~scanf("%d",&n) && n){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d",&mp[i][j]);
            }
        }
        step = 0;
        printf("%d %d\n",dfs(0) + mp[n/2][n/2] ,step);
    }
}