//
// Created by Henry on 16/11/8.
//

//巴什博奕
#include <cstdio>
#include <memory.h>
#define LowBit(x) (x&(-x))

const int MAXN = 1000;

using namespace std;
//int dp[MAXN + 10];
//
//int Grundy(int n){
//    if (~dp[n]){
//        return dp[n];
//    }
//
//    int ans = 0;
//    for (int i = 1; i < n; i<<=1) {
//        ans ^=  Grundy(n-i);
//    }
//    return dp[n] = ans;
//}
//
//void init(){
//    memset(dp,-1, sizeof(dp));
//}

int main(){
    int n;

    while (~scanf("%d",&n)){
        puts(n % 3 ? "Kiki" : "Cici");
    }
}
