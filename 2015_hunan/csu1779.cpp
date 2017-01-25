//
// Created by Henry on 17/1/18.
//
#include<cstdio>
#include <memory.h>
const int MAXN = 500 + 10;
int n,m,r[MAXN],c[MAXN];
int mp[MAXN][MAXN];


int wrong(){
    int ansr,ansc;
    ansc = ansr = 0;
    for (int i = 1; i < n; ++i) {
        if (r[ansr] < r[i]){
            ansr = i;
        }
    }

    for (int i = 1; i < m; ++i) {
        if (c[ansc] < c[i]){
            ansc = i;
        }
    }
    return r[ansr] + c[ansc] - mp[ansr][ansc];
}

bool correct(int fuck){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fuck < r[i] + c[j] - mp[i][j])return false;
        }
    }

    return true;
}

void init(){
    memset(r,0, sizeof(r));
    memset(c,0, sizeof(c));
}

int main(){
    int cases = 0;
    while (~scanf("%d%d",&n,&m)){
        init();

        printf("Case %d: ",++cases);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d",&mp[i][j]);
                r[i] += mp[i][j];
                c[j] += mp[i][j];
            }
        }

        puts(correct(wrong()) ? "Weak" : "Strong");

    }



}
