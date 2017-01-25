//
// Created by Henry on 16/11/3.
//
/*
HDU 4098
题意：有n个人排队等着在官网上激活游戏。Tomato排在第m个。
对于队列中的第一个人。有一下情况：
1、激活失败，留在队列中等待下一次激活（概率为p1)
2、失去连接，出队列，然后排在队列的最后（概率为p2）
3、激活成功，离开队列（概率为p3）
4、服务器瘫痪，服务器停止激活，所有人都无法激活了。
求服务器瘫痪时Tomato在队列中的位置<=k的概率

解析：
概率DP；
设dp[i][j]表示i个人排队,Tomato排在第j个位置，达到目标状态的概率(j<=i)
dp[n][m]就是所求
j==1:    dp[i][1]=p1*dp[i][1]+p2*dp[i][i]+p4;
2<=j<=k: dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4;
k<j<=i:  dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1];
化简：
j==1:    dp[i][1]=p*dp[i][i]+p41;
2<=j<=k: dp[i][j]=p*dp[i][j-1]+p31*dp[i-1][j-1]+p41;
k<j<=i:  dp[i][j]=p*dp[i][j-1]+p31*dp[i-1][j-1];

其中:
p=p2/(1-p1);
p31=p3/(1-p1)
p41=p4/(1-p1)

可以循环i=1->n 递推求解dp[i].在求解dp[i]的时候dp[i-1]就相当于常数了。
在求解dp[i][1~i]时等到下列i个方程
j==1:   dp[i][1]=p*dp[i][i]+c[1];
2<=j<=k:dp[i][j]=p*dp[i][j-1]+c[j];
k<j=i:  dp[i][j]=p*dp[i][j-1]+c[j];
其中c[j]都是常数了。上述方程可以解出dp[i]了。
首先是迭代得到 dp[i][i].然后再代入就可以得到所有的dp[i]了。

注意特判一种情况。就是p4<eps时候，就不会崩溃了，应该直接输出0
*/
#include <cstdio>

#define EPS 1e-9

const int MAXN = 2000 + 10;

int n,m,k;
double p1,p2,p3,p4,p21,p31,p41;

double dp[MAXN][MAXN],c[MAXN];

int main(){
    while (~scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)){
        if (p4 <= EPS){
            puts("0.00000");
            continue;
        }

        double div = 1-p1;
        p21 = p2/div;
        p31 = p3/div;
        p41 = p4/div;

        dp[1][1] = p4/(div-p2);
        for (int i = 2; i <=n ; ++i) {
            for (int j = 2; j <= (i<k?i:k) ; ++j) {
                c[j] = dp[i-1][j-1]*p31 + p41;
            }
            for (int j = k+1; j <= i; ++j) {
                c[j] = dp[i-1][j-1]*p31;
            }

            double p=1,tmp = 0;
            for (int j = i; j >1  ; --j) {
                tmp += p*c[j];
                p*=p21;
            }

            dp[i][i] = (tmp+p*p41)/(1-p*p21);
            dp[i][1] = p21*dp[i][i] + p41;

            for (int j = 2; j < i; ++j) {
                dp[i][j] = p21 * dp[i][j-1] + c[j];
            }
        }

        printf("%.5f\n",dp[n][m]);

    }
}

