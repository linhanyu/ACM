//
// Created by Henry on 16/8/3.
//

#include <cstdio>
#include <algorithm>
#include <climits>
#define NUM 100001

using namespace std;

void scanRight(__int64 A[],__int64 map[],__int64 n){
    __int64 tmp ;
    for (__int64 i = n-1; i >= 1; --i) {
        tmp = i;
        while (tmp < n && map[i] <= map[tmp+1]){
            tmp = A[tmp+1];
        }
        A[i] = tmp;
    }
}

void scanLeft(__int64 A[], __int64 map[],__int64 n){
    __int64 tmp ;
    for (__int64 i = 2; i <= n; ++i) {
        tmp = i;
        while (tmp > 1 && map[i] <= map[tmp-1]){
            tmp = A[tmp-1];
        }
        A[i] = tmp;
    }
}

int main(){
    __int64 l[NUM],r[NUM],map[NUM];
    __int64 n;
    while(scanf("%I64d",&n)!=EOF && n){
        for (__int64 i = 1; i <= n ; ++i) {
            scanf("%I64d",&map[i]);
        }

        l[1] = 1;
        r[n] = n;

        scanLeft(l,map,n);
        scanRight(r,map,n);

        __int64 Max = -1;
        for (__int64 i = 1; i <= n ; ++i) {
            Max = max((r[i]-l[i]+1)*map[i],Max);
        }

        printf("%I64d\n",Max);
    }
}