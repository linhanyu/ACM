//
// Created by Henry on 16/10/27.
//


#include <cstdio>
#include <memory.h>
#include <cmath>
using namespace std;

const int MAXN = 16000 + 10;

bool prime[MAXN];

void init(){
    memset(prime,1, sizeof(prime));

    int cur = 0;

    for (int i = 2; i <= sqrt(MAXN) ; ++i) {

        if (prime[i]){
            for (int j = i<<1; j < MAXN; j += i) {
                prime[j] = false;
            }
        }
    }

    prime[0] = prime[1] = prime[2] = false;
}

int main(){
    init();

    int n,cases = 1;
    while (~scanf("%d",&n) && n>0){
        printf("%d: %s\n",cases++,prime[n] ? "yes" : "no");
    }
}