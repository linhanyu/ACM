//
// Created by Henry on 17/2/1.
//
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int block[MAXN];

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);

        int n,k,sum = 0;
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&block[i]);
            sum += block[i];
        }

        if (sum % k) {
            puts("-1");
            continue;
        }

        sort(block,block + n);
        int op = 0,target = sum/k;
        int i = 0,j = n-1;

        for(;i < j;){
            while (block[i] < target){
                int r1 = block[i] - target,r2 =  block[j] - target;
                if (r1 < r2){
                    block[j] -= r1;
                    i++;
                } else{
                    block[i] += r2;
                    j--;
                }
                op += 2;
            }
        }
    }

}