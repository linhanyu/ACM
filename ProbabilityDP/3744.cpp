//
// Created by Henry on 16/11/5.
//

#include <cstdio>
#include <algorithm>
#include <set>

#define MID(a,b) ((a+b)>>1)

typedef long long LL;

using namespace std;

const int MAXN = 3;
const int MAXR = 2;
int n,cur;

double p;

LL stack[15];

struct matrix{
    double A[MAXR][MAXR];


    void E(){
        for (int i = 0; i < MAXR; ++i) {
            for (int j = 0; j < MAXR; ++j) {
                A[i][j] = i==j;
            }
        }
    }

};

matrix operator*(const matrix & m1,const matrix & m2) {
    matrix tmp;

    memset(tmp.A,0, sizeof(tmp.A));

    for (int k = 0; k < MAXR; ++k) {
        for (int i = 0; i < MAXR; ++i) {
            for (int j = 0; j < MAXR; ++j) {
                tmp.A[i][j] += m1.A[i][k] * m2.A[k][j];
            }
        }
    }

    return tmp;
}


matrix fastPow(matrix & base,LL pow){
    matrix ans;
    ans.E();

    while (pow){
        if (pow & 1){
            ans = ans * base;
        }
        base = base * base;
        pow>>=1;
    }

    return ans;
}

int main(){

    stack[0] = 0;
    while (~scanf("%d %lf",&n,&p)){
        for (int i = 1; i <= n; ++i) {
            int tmp;
            scanf("%lld",&stack[i]);
        }
        sort(stack,stack + n + 1);

        matrix A;
        matrix x;
        double dn = 1;

        for (int i = 1; i <= n; ++i) {
            A.A[0][0] = p;
            A.A[0][1] = 1-p;
            A.A[1][0] = 1;
            A.A[1][1] = 0;

            matrix a = fastPow(A,stack[i] - stack[i-1]);

            x.A[0][0] = 0;
            x.A[0][1] = 0;
            x.A[1][0] = dn;
            x.A[1][1] = 0;

            matrix B = a*x;

            dn = B.A[1][0];
        }

        printf("%.7f\n",dn);

    }
}