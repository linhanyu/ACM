//
// Created by Henry on 16/12/11.
//

#include <cstdio>
#include <memory.h>
typedef long long LL;

const int MOD = 7;
const int MAXN  = 100;
const int nsquare[] = {0,1,4,6,4,3,1,0,1,1,4,2,1,6,0,1,2,5,1,5,1,0,1,4,1,4,4,6,0,1,1,3,2,6,1,0,1,2,2,1,2,6,0,1,4,6};
const char HASH[][10] = {"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int Sum[44];
//int test[MAXN];
//LL fpow(LL base,int m){
//    LL ans = 1;
//    while (m){
//        if (m & 1) ans = base * ans % MOD;
//        base = base * base % MOD;
//        m>>=1;
//    }
//    return ans;
//}

void init(){
//    memset(test,0, sizeof(test));
//    test[1] = 1;
//    printf("1");
//    for (int i = 2; i <= 100 ; ++i) {
//        test[i] = (test[i-1] + fpow(i,i))%MOD;
//    }
//    puts("");
    Sum[0] = 0;
    for (int i = 1; i <= 43 ; ++i) {
        Sum[i] = (Sum[i-1] + nsquare[i]) % MOD;
    }
}

int res(int n){

    return (n/42*Sum[42]%MOD + Sum[n%42])%MOD;
}

int main(){
    init();
    int t;
    scanf("%d",&t);
    while (t--){
        int tmp;
        scanf("%d",&tmp);
        printf("%s\n",HASH[res(tmp)]);

    }
}