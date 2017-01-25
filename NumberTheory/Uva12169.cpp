//
// Created by Henry on 16/10/30.
//

#include <cstdio>

typedef long long LL;

using namespace std;

const int MOD = 10001;
const int MAXN = 210;

LL x[MAXN];
int n;

//xi = (axi-1 + b)%MOD

//x[2] = a*x[1] + b mod
//x[3] = a*x[2] + b mod
//x[3] = (a*(a*x[1] + b )mod + b )mod =(a*(a*x[1] + b) + b )mod
//a^2x[1] + (a+1)b = kmod + x[3]
//(a+1)b + (-kmod) = x[3] - a^2x[1]

LL exgcd(LL a,LL b,LL & x,LL & y){
    LL d;

    if (b){
        d = exgcd(b,a%b,y,x);
        y -= x*(a/b);
    } else{
        d = a;
        x = 1;
        y = 0;
    }

    return d;
}

bool getx(LL a,LL b){
    for (int i = 2; i <= n; i ++) {
        LL tmp = (a*x[i-1] + b) %MOD;

        if (i&1){
            if (tmp != x[i]) return false;

        } else{
            x[i] = tmp;
        }
    }
    return true;
}

void solve(){
    for (int a = 0; a < MOD; ++a) {
        LL d,t;
        LL b,k;

        t = x[3] - a*a*x[1];
        d = exgcd(a+1,MOD,b,k);

        if (t % d) continue;

        b = b*t/d;
        if (getx(a,b)) {
            for (int i = 2; i <= n; i +=2) {
                printf("%lld\n",x[i]);
            }
            break;
        }

    }
}

int main(){
    scanf("%d",&n);
    n<<=1;
    for (int i = 1; i < n; i += 2) {
        scanf("%lld",&x[i]);
    }
    solve();
}

//#include<stdio.h>
//#include<algorithm>
//#include<iostream>
//#include<cmath>
//#include<cstring>
//#include<vector>
//#include<queue>
//using namespace std;
//
//#define ll long long
//const int mod=10001;
//int x1[105],x3[205];
//int T;
//ll a,b,y;
//
//ll extendGcd(ll a,ll b,ll &x,ll &y){
//    ll ans,t;
//    if(b==0){
//        x=1;y=0;
//        return a;
//    }
//    ans=extendGcd(b,a%b,x,y);
//    t=x;x=y;y=t-(a/b)*y;
//    return ans;
//}
//
//int getx3(){
//    memset(x3,0,sizeof(x3));
//    x3[1]=x1[1];
//    for(int i=2;i<=2*T;i++){
//        x3[i]=(a*x3[i-1]+b)%mod;
//    }
//    for(int i=1;i<=T;i++){
//        if(x1[i]!=x3[i*2-1])return 0;
//    }
//    return 1;
//}
//
//int main()
//{
//    cin>>T;
//    for(int i=1;i<=T;i++){
//        scanf("%lld",x1+i);
//    }
//    for(int i=0;i<mod;i++){
//        a=i;
//        ll temp=x1[2]-a*a*x1[1];
//        ll t=extendGcd(a+1,mod,b,y);
//        if(temp%t)continue;//不是倍数，无解
//        b=b*temp/t;//是倍数,等比例扩大一下，解得b
//        if(getx3())break;
//    }
//    for(int i=1;i<=T;i++)cout<<x3[i*2]<<endl;
//    return 0;
//}