//
// Created by Henry on 16/10/31.
//
#include <cstdio>
#include <memory.h>

const int MAXN = 50001;

int phi[MAXN];
int n;
void initEularTable(){
    memset(phi,0, sizeof(phi));

    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]){
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]){
                    phi[j] = j;

                }
                phi[j] = phi[j] / i * (i-1);


            }

        }
    }

}

void init(){
    initEularTable();

    for (int i = 3; i < MAXN ; ++i) {
        phi[i] += phi[i-1];
    }



}
//
//void solve(){
//
//}

int main(){
    init();

    while(~scanf("%d",&n) && n) {
        printf("%d\n",n == 1 ? 1 : 2*phi[n] + 1);
    }
}
