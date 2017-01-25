//
// Created by Henry on 16/10/27.
//

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <memory.h>

using namespace std;
const int MAXK = 10;

int spell[MAXK];
int dspell[MAXK];
int dp[1<<MAXK];

int m,k,Maxdepth;

void init(){
    memset(spell,0, sizeof(spell));
    memset(dspell,0, sizeof(dspell));
}

void dfs(int m,int d){

    if(d > Maxdepth) return;

    if (m<=0) {
        Maxdepth = d;
        return;
    }


    for (int i = 0; i < k; ++i) {
        if (spell[i]){
            int tmp = spell[i];
            if (m <= dspell[i]) tmp <<= 1;

            m -= tmp;
            spell[i] = 0;

            dfs(m,d+1);

            spell[i] = tmp;
            m += tmp;
            if (m < dspell[i]) spell[i] >>= 1;


        }
    }


}

int idaStar(int m,int k){
//    for (Maxdepth = 1; Maxdepth <=k ; ++Maxdepth) {
//        if (dfs(m,0)) break;
//    }
    Maxdepth = k+1;
    dfs(m,0);
    return Maxdepth > k ? -1 : Maxdepth;
}

int main(){
    while (~scanf("%d %d",&k,&m)){
        init();
        for (int i = 0; i < k; ++i) {
            scanf("%d%d",&spell[i],&dspell[i]);
        }

        printf("%d\n",idaStar(m,k));
    }
}