//
// Created by Henry on 17/1/29.
//

#include<cstdio>
#include <memory.h>
#include <cmath>
const int MAXN =  10000000;

bool prime[MAXN];

void init(){
    memset(prime,1, sizeof(prime));
    for (int i = 2; i < MAXN; ++i) {
        if (prime[i]){
            for (int j = i*i; j < MAXN ; j += i) {
                prime[j] = false;
            }
            printf("%d,\n",i);
        }

    }
}

int main(){
    int t;
    scanf("%d",&t);
    init();
    while (t--){
        int x;
        scanf("%d",&x);
    }
}