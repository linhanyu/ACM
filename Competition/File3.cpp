//
// Created by Henry on 16/9/10.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 9999999;

long long fastpow(long long base,long long mi){
    long long ans = 1;
    while (mi){
        if (mi&1){
            ans *= base;
        }
        base*=base;
        mi>>=1;

    }

    return ans;
}


int main()
{
    long long k = 1<<4;
    for (int i = 3; i >= 0 ; ++i) {
        k-= 1<<i;
    }

    cout<<k<<endl;

}