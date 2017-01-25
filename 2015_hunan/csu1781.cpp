//
// Created by Henry on 17/1/18.
//

#include <cstdio>
#include <memory.h>

typedef long long LL;


int main(){
    int t,n,cases = 0;
    while (~scanf("%d",&t)){
        printf("Case %d: ",++cases);
        if (t == 1){
            puts("Impossible");
            continue;
        }
        bool flg = true;
        for (int i = 2;i*i <= t; ++i) {
            int tmp = t,cnt=i;
            while (tmp > 1 && !(tmp % cnt)) tmp/=cnt++;

            if (tmp == 1){
                printf("%d %d\n",cnt-1,i-1);
                flg = false;
                break;
            }
        }
        if (flg) printf("%d %d\n",t,t-1);
    }
}