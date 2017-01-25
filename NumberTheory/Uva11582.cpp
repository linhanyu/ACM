//
// Created by Henry on 16/10/30.
//
#include <cstdio>

typedef unsigned long long ULL;
const int MAXN = 1001;

ULL fib[MAXN][MAXN*6];
int g[MAXN];

ULL fastPowMod(ULL base,ULL pow,int MOD){
    ULL ans = 1;
    while (pow){
        if (pow&1){
            ans = ans * base % MOD ;
        }

        base = base * base % MOD;
        pow >>= 1 ;
    }

    return ans;
}


void init(){
    for (int i = 2; i < MAXN; ++i) {
        fib[i][0] = 0;
        fib[i][1] = 1;
        for (int j = 2;  ; ++j) {
            fib[i][j] = (fib[i][j-1] + fib[i][j-2]) % i;
            if (fib[i][j-1] == 0 && fib[i][j] == 1){
                g[i] = j-1;
                break;
            }
        }
    }
}

int main(){
    int t;
    ULL a,b,n;

    init();

    scanf("%d",&t);


    while (t--){
        scanf("%llu %llu %llu",&a,&b,&n);
        if (a == 0 || n == 1){
            puts("0");
        } else{
            ULL p = fastPowMod(a%g[n],b,g[n]);
            printf("%d\n",(int)fib[n][p]);
        }
    }
}
