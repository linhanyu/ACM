//
// Created by Henry on 16/11/2.
//

//P(Ai/B) = P(AiB)/P(B)
#include <cstdio>

#define EPS 1e-9

const int MAXN = 20 + 2;

double PAi[MAXN],PB,PAiB;
int n,r,jumppos;

double setPcd(int pos,int status,int d){

    if (d == r){
        double ans = 1;
        for (int i = 0; i < n; ++i) {
            if (status & (1<<i)){
                ans *= PAi[i];
            } else{
                ans *= 1-PAi[i];
            }
        }

        return ans;
    }

    if (pos >= n || d>r){
        return 0;
    }

    double ans = 0;
    if (!(status & (1<<pos))){
        ans += setPcd(pos+1,status | (1<<pos),d+1);
    }

    ans += setPcd(pos+1,status,d);

    return ans;
}

//double dfs(int r,int pos,int d, double ans){
//
//    if (d <= r && pos == jumppos){
//        return dfs(r,pos+1,d,ans);
//    }
//
//
//
//    if (pos == n){
//        return -1;
//    }
//
//
//
//    double res = 0,tmp,tmpans = ans;
//
//    ans *= tmpans * PAi[pos];
//    if (d <= r && (tmp = dfs(r,pos+1,d+1,ans)) > 0 ){
//        res += tmp;
//    }
//
//    ans = tmpans * (1-PAi[pos]);
//    if ((tmp = dfs(r,pos+1,d,ans)) > 0  ){
//        res += tmp;
//    }
//xq
//    return res;
//}

int main(){
    int cnt = 0;
    while (~scanf("%d%d",&n,&r) && n+r){
        printf("Case %d:\n",++cnt);

        jumppos = -1;
        for (int i = 0; i < n; ++i) {
            scanf("%lf",&PAi[i]);
        }

        PB = setPcd(0,0,0);
        double tmp,PBAi;

        for (int i = 0; i < n; ++i){
            printf("%.6lf\n",setPcd(0,1<<i,1)/PB);
        }

    }
}