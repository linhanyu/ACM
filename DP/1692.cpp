//
// Created by Henry on 16/8/9.
//
#include <cstdio>
#include <algorithm>

#define NUM 100010
#define INF 0x7FFFFFF
using namespace std;

int w[NUM],l[NUM],p[NUM];
int main(){
    int t,n,count = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for (int i = 1; i <= n ; ++i) {
            scanf("%d %d %d",&w[i],&l[i],&p[i]);
        }

        int ans = INF;
        for (int i = 1; i <=  n ; ++i) {
            int sum = 0,carry = 0;
            for (int j = i; j <= n ; ++j) {
                carry += w[j];
                if (carry <= l[j]) {
                    sum += p[j];
                }
                if (sum > ans) break;
            }
            ans = min(sum,ans);
        }
        printf("Case %d: Need to use %d mana points.\n",count++,ans);
    }
}