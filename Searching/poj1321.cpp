//
// Created by Henry on 16/10/20.
//

#include <cstdio>

const int MAXN = 9;

int n,k;
char map[MAXN][MAXN];

int dfs(int row,int status,int remain){
    if (remain == 0) return 1;

    if (row == n || (n-row) < remain ) return 0;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        int cur = 1<<i;

        if(map[row][i] == '#' && !(status & cur)){

            res += dfs(row+1,status | cur,remain-1);

        }
    }

    res += dfs(row+1,status,remain);

    return res;
}

void solve(){
    printf("%d\n",dfs(0,0,k));
}

void readData(){
    for (int i = 0; i < n; ++i) {
        scanf("%s",map[i]);
    }
}

int main(){

    while (~scanf("%d %d",&n,&k) && ~n && ~k){
        readData();

        solve();
    }

}