//
// Created by Henry on 17/3/5.

#include <cstdio>
#include <algorithm>
using namespace std;
long long s[40];
int main()
{
    long long t,n,i;
    s[0] = 1;
    for(i=1; i<33; i++)s[i] = s[i-1]*2;
    while(scanf("%lld",&t)!=EOF)
        while(t--)
        {
            scanf("%lld",&n);
            printf("%lld\n",upper_bound(s,s+33,n) - s);

        }
    return 0;
}


