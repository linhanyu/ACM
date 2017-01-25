//
// Created by Henry on 16/10/30.
//

#include <cstdio>

typedef long long LL;

LL deconstruct(LL num){
    LL ans = 0;
    int factor = 0;
    LL raw = num;
    for (LL i = 2; i*i <= num ; ++i) {
        if (num % i == 0){
            factor++;
            int fac = 1;
            while (num % i == 0){
                fac *= i;
                num /= i;
            }
            ans+=fac;
        }

    }

    if (num > 1){
        if (factor == 0) ans++;
        ans += num;
    }else if (factor == 1){
        ans = raw+1;
    }



    return ans;
}


int main(){
    LL num;
    int count = 1;
    while (~scanf("%lld",&num) && num){
        if (num == 1){
            printf("Case %d: 2\n",count++);
            continue;
        }
        printf("Case %d: %lld\n",count++,deconstruct(num));
    }
}