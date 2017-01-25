//
// Created by Henry on 16/10/30.
//

#include <cstdio>
#include <memory.h>
#include <cmath>
const int MAXN = 10010;

bool prime[MAXN];
int pstack[MAXN];
int pcounter[MAXN];

int cur,p,q,r,s;

void init(){
    memset(prime,1, sizeof(prime));
    cur = 0;

    for (int i = 2; i < MAXN ; ++i) {
        if (prime[i]){
            pstack[cur++] = i;
            for (int j = i*i; j < MAXN; j += i) {
                prime[j] = 0;
            }
        }

    }
}

void addfactor(int n,int step){
    for (int i = 0; i < cur && n!=1; ++i) {
        while(n % pstack[i] == 0){
            pcounter[i] += step;
            n /= pstack[i];

        }
    }
}

void addcfactor(int begin,int end,int step){
    for (int i = begin; i <= end ; ++i) {
        addfactor(i,step);
    }

}



void solve(){
    memset(pcounter,0, sizeof(pcounter));

    addcfactor(p-q+1,p,1);
    addcfactor(2,q,-1);
    addcfactor(r-s+1,r,-1);
    addcfactor(2,s,1);

    double ans = 1;
    for (int i = 0; i < cur; ++i) {
        if (pcounter[i]){
            ans *= pow(pstack[i],pcounter[i]);
        }
    }

    printf("%.5lf\n",ans);
}



int main(){
//    freopen("/t10375.txt","r",stdin);

    init();
    while (~scanf("%d%d%d%d",&p,&q,&r,&s)){
        solve();
    }

}