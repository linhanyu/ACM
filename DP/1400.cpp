//
// Created by Henry on 16/7/26.
//

#include <cstdio>
#include <algorithm>

#define NUM 13

using namespace std;

int n,m,statuUpper;
long long dp[NUM][1<<NUM];

bool isOkay(int status){
    //仅仅是第一行的状态处理
    int i=0;
    while(i<m){
        if (status & (1<<i)){
            //状态扫描
            if ((status & (1 << (i + 1))) == 0 || i == m-1) return false;
            //扫到1时,检查1后面一位.根据上面的压缩大法,一行里必定有偶数个连续的1.不符合条件就错了
            i+= 2;
        } else{
            i++;
        }
    }
    return true;
}

bool is_legal(int status1,int status2){
    int i=0;
    while(i<m){
        if ((status2 & (1<<i)) == 0){
            //扫出0.那么,状态1的相同位置的位必须为1
            if ((status1 & (1<<i)) == 0){
                return false;
            }
            i++;
        }else{
            //扫出1
            if((status1 & (1<<i)) == 0){
                //上面为0,则该位置合法
                i++;
            } else if(i == m-1 || !((status1 & 1 << (i + 1)) && (status2 & 1 << (i + 1)))) {
                //i为1且j也为1,则下一位也必须为1.若非,则不合法
                return false;
            } else{
                i += 2;
            }
        }
    }
    return true;
}

int main(){

    while(scanf("%d %d",&n,&m)!=EOF && (m || n)){
        if (m > n) swap(m,n);

        if ((n*m)&1){
            //面积为奇数,必定儿不能
            printf("0\n");
            continue;
        }

        statuUpper = 1<<m;
        memset(dp,0, sizeof(dp));
        //状态压缩.横为11,竖为01.也即,最后一列必定为全0;

        for (int i = 0; i < statuUpper; ++i) {
            if (isOkay(i)) dp[0][i] = 1;
        }


        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < statuUpper; ++j) {
                for (int k = 0; k < statuUpper; ++k) {
                    if (is_legal(k,j)){
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }

        printf("%lld\n",dp[n-1][statuUpper-1]);


    }
}