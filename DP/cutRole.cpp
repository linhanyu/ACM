//
// Created by Henry on 16/7/14.
//

#include <algorithm>

using namespace std;

#define NUM 100
#define INF 0x7fffffff

int Button_up_Cut(int piece[],int s[],int n){
    int r[NUM];
    r[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int q = -INF;
        for (int j = 1; j <= i; ++j) {
            if (piece[j] + r[ i - j ] > q ) {
                q = piece[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    return r[n];
}


int prt_Solution(int s[],int n){
    while( n > 0){
        printf("%d",s[n]){
            n = n-s[n];
        }
    }
}