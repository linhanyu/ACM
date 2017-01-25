//
// Created by Henry on 16/10/18.
//

#include <cstdio>
#include <cmath>
#include <memory.h>

const int MAXN = 10000;

bool prime[MAXN];

void init(){
    memset(prime,1, sizeof(prime));

    prime[0] = prime[1] = false;
    int ubound = (int ) sqrt(MAXN);

    for (int i = 2; i <= ubound; ++i) {
        if (prime[i]){
            for (int j = (i<<1); j < MAXN; j += i) {
                prime[j] = false;
            }

        }
    }
}

//void init(){
//    memset(prime,1, sizeof(prime));
//
//    prime[0] = prime[1] = false;
////    int ubound = (int ) sqrt(MAXN);
//
//    for (int i = 2; i <= sqrt(MAXN); ++i) {
//        if (prime[i]){
//            for (int j = i*2; j < MAXN; j += i) {
//                prime[j] = false;
//            }
//
//        }
//    }
//}
//
//bool isPrime(int num){
//    return prime[num];
//
//}

//bool isPrime(int num){
//    if (num == 1) return false;
//
//    for (int i = 2; i <= sqrt(num); ++i) {
//        if (num % i == 0){
//            return false;
//        }
//    }
//
//    return true;
//
//}

bool isPrime(int num){
    if (num == 1) return false;

    for (int i = 2; i <= num-1; ++i) {
        if (num % i == 0){
            return false;
        }
    }

    return true;

}

int main(){
    int tmp;
    init();

    while(scanf("%d",&tmp) && tmp){
        printf("%s\n",isPrime(tmp) ? "YES":"NO");
//        printf("%s\n",prime[tmp] ? "YES":"NO");
    }

}