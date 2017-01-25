//
// Created by Henry on 16/10/27.
//

#include <cstdio>
#include <memory.h>
using namespace std;

const int MAXN = 1000000 + 10;

bool prime[MAXN];
int primeFactor[MAXN];

void init(){
    memset(prime,1, sizeof(prime));

    int cur = 0;

    prime[0] = prime[1] = false;
    primeFactor[0] = primeFactor[1] = 0;

    for (int i = 2; i <= MAXN ; ++i) {

        if (prime[i]){
            primeFactor[i] = ++cur;
            for (int j = i<<1; j < MAXN; j += i) {
                prime[j] = false;
                primeFactor[j] = cur;
            }
        }
    }
}

int main(){
    init();

    int n;
    while (~scanf("%d",&n)){
        printf("%d\n",primeFactor[n]);
    }
}