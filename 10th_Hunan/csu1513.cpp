//
// Created by Henry on 17/1/23.
//

#include <cstdio>
#include <memory.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))

double ta[5],tb[5];
int sA,sB;

double dp[6][6][6][6];
bool vis[6][6][6][6];
double dfs(int apos,int bpos,int a,int b,bool turn){

    if (a > sA || b > sB ) return 0;

    if ((apos == 5 && bpos == 5)|| 5 - apos + a < b || 5-bpos + b < a) {
        //赛完
        if (a == sA && b == sB) return 1;
        else return 0;
    }

    if (vis[apos][bpos][a][b]){
        return dp[apos][bpos][a][b];
    }

    vis[apos][bpos][a][b] = true;

    if (turn){
        //a射
        return dp[apos][bpos][a][b] = dfs(apos+1,bpos,a+1,b,0) * ta[apos] + dfs(apos+1,bpos,a,b,0) * (1-ta[apos]);

    } else{
        return dp[apos][bpos][a][b] = dfs(apos,bpos+1,a,b+1,1) * tb[bpos] + dfs(apos,bpos+1,a,b,1) * (1-tb[bpos]);
    }

}

void init(){
    memset(vis,0, sizeof(vis));
}

int main(){
    int cases = 0;
    while (~scanf("%lf",&ta[0])){
        init();
        printf("Case %d: ",++cases);

        for (int i = 1; i < 5; ++i) {
            scanf("%lf",&ta[i]);
        }

        for (int i = 0; i < 5; ++i) {
            scanf("%lf",&tb[i]);
        }

        scanf("%d-%d",&sA,&sB);

        printf("%.2lf%%\n",dfs(0,0,0,0,1)*100);
    }
}