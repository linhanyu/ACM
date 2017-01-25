//
// Created by Henry on 17/1/22.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int dir[][2]= {{0,1},{-1,0},{0,-1},{1,0}};
//0:上 1:左
const int MAXN = 1000 + 10;
const int INF = -0x3f3f3f3f;
int dp[MAXN][4],len;
bool vis[MAXN][4];
char str[MAXN];

int dfs(int pos,int d,int xy,const int & (*f)(const int &, const int &)){
    if (vis[pos][d]) return dp[pos][d];

    if (pos == len) return 0;

    if (str[pos] == 'F'){
        dp[pos][d] = dfs(pos+1,d,xy,f) + dir[d][xy];
    } else if (str[pos] == 'L'){
        dp[pos][d] = dfs(pos + 1, (d + 1) % 4,xy,f);
    } else if (str[pos] == 'R') {
        dp[pos][d] = dfs(pos + 1, (d + 3) % 4,xy,f);
    } else{
        dp[pos][d] = f(dfs(pos + 1, (d + 3) % 4,xy,f),f(dfs(pos + 1, (d + 1) % 4,xy,f),dfs(pos+1,d,xy,f) + dir[d][xy]));
    }

    vis[pos][d] = true;
    return dp[pos][d];
}
void init(){
    str[0] = '0';
    len =strlen(str);
}

int solve(int pos,int d,int xy,const int & (*f)(const int &, const int &)){
    memset(vis,0, sizeof(vis));
    return dfs(pos, d , xy,f);
}

int main(){
    int cases = 0;
    while (~scanf("%s",str + 1)){
        init();
        printf("Case %d: %d %d %d %d\n",++cases,solve(1,3,0,min),solve(1,3,0,max),solve(1,3,1,min),solve(1,3,1,max));

    }
}