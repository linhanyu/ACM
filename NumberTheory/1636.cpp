//
// Created by Henry on 16/10/31.
//
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define EPS 1e-8

const int MAXN = 120;


int num[2];
char seq[MAXN];

int len;

void solve(){
    num[0] = num[1] = 0;
    int cZero = 0;

    for (int i = 0; i < len; ++i) {
        num[seq[i] - '0']++;
    }

    seq[len] = seq[0];

    for (int i = 0; i < len; ++i) {
        if (seq[i] == '0' && seq[i+1] == '0') cZero++;
    }

    double pbr = (double)num[0]/len;
    double pbs = (double)cZero/num[0];

    if (abs(pbr - pbs) <= EPS){
        puts("EQUAL");
    } else if (pbr < pbs){
        puts("SHOOT");
    } else{
        puts("ROTATE");
    }

}

int main(){
    while(~scanf("%s",seq)){
        len = strlen(seq);

        solve();
    }
}
