//
// Created by Henry on 16/11/2.
//
#include <cstdio>

const int MAXP = 9;
const int MAXN = 5;

int dp[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];
int topcur[MAXP];

double cal;

void init(){
    for (int i = 0; i < MAXP; ++i) {
        topcur[i] = 4;
    }
}
int main(){

}