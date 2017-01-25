//
// Created by Henry on 16/11/28.
//

#include <cstdio>
#include <memory.h>
typedef long long LL;

using namespace std;

int bit[20];
LL dp[20][20];
char s[20];
//LL dfs(int p,int m, bool flag){
//    //前1~p位,和为m的方法总数
//
//    if (p == 0) return m == 0;
//    //和为0,则为一种可行解
//    if (flag && ~dp[p][m]) return dp[p][m];
//    //
//    int len = flag ? 9 : bit[p];
//
//    LL res = 0;
//    for (int i = 0; i <= len; ++i) {
//        //0~bit[p]的结果都求出来
//        res += dfs(p-1 ,(m+i)%10,flag || i != len);
//    }
//
//    if (flag) dp[p][m] = res;
//    return res;
//}

//LL get(LL n){
//    if (n < 0) return 0;
//
//    int cur = 0;
//    while (n != 0){
//        bit[++cur] = n%10;
//        n/=10;
//    }
//
//    memset(dp,0, sizeof(dp));
//    for (int i = 1; i <= cur; ++i) {
//        //dp[i]
//
//    }
//
////    return dfs(cur,0,0);
//}

void DP(){
    memset(dp,0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 18; ++i) {
        //1~18位
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                dp[i][(j+k) % 10] += dp[i-1][j];
                //1~i位模和为j+k,加上结果为前(i-1)位,模和为j的dp值

            }
        }
    }
}

LL count(LL x){
    int len;
    LL p = 0,ans = 0;
    sprintf(s ,"%lld",x);
    len = strlen(s);

    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < s[i-1] - '0'; ++j) {
            ans += dp[len - i][(1000 - j - p)%10];

        }
        p += s[i-1] - '0';
    }

    if (p % 10 == 0) ans++;
    return ans;
}

int main()
{
    int C,cases;
    LL A,B;
    DP();
    scanf("%d",&C);
    for (cases=1;cases<=C;cases++)
    {
        scanf("%lld%lld",&A,&B);
        printf("Case #%d: %lld\n",cases,count(B)-count(A-1));
    }
    return 0;
}