//
// Created by Henry on 16/11/2.
//

#include <cstdio>

const int MAXN = 1000 + 1;

double dp[MAXN][MAXN];

void init(){

    //0公主,1怪兽

    dp[0][0] = 0;
    //没老鼠,怪兽赢
    for (int i = 1; i < MAXN; ++i) {
        dp[i][0] = 1;
        //只有白鼠,公主赢
        dp[0][i] = 0;
        //只有黑鼠,怪兽赢
    }



    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            //i个白鼠,j个黑鼠
            //dp[i][j][0] =  (2-dp[i+1][j][1]-dp[i][j+1][1] )* i/(i+j)
            //dp[i][j][1] = (1-dp[i][j][0]) * i/(i+j)
            dp[i][j] = (double)i/(i+j);
            if (j>=2){
                //抓俩黑,跑白
                dp[i][j] += dp[i-1][j-2] * j/(i+j)* (j-1)/(i+j-1) * i/(i+j-2) ;
            }

            if (j>=3){
                //抓俩黑,跑黑
                dp[i][j] += dp[i][j-3] * j/(i+j)* (j-1)/(i+j-1) * (j-2)/(i+j-2) ;
            }
        }
    }

}

int main(){
    init();

    int w,b;
    while (~scanf("%d%d",&w,&b)){
        printf("%.9lf\n",dp[w][b]);
    }
}