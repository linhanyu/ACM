//
// Created by Henry on 17/1/26.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define lowbit(a) (a&(-a))

using namespace std;

typedef long long LL;
//
const int MAXN = 1000000000 ;


int main(){

    int x,y,cases = 0;
    while (~scanf("%d%d",&x,&y)){
        LL ans = 0;
        int k = pow(y*10 + 3,1.0/3);

        for (int a = x; a <= k ; ++a) {
            for (int b =x; b <= k ; ++b) {
                int tmp=(a*a*a+b*b*b);
                if(tmp>y*10+3)continue;
                if(tmp%10==3)ans++;
            }
        }
        printf("Case %d: %lld\n",++cases,ans);
    }
}