//
// Created by Henry on 16/12/11.
//

#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n,m;
        scanf("%d%d",&n,&m);
        int maxn = 0,sum = 0;

        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d",&tmp);
            sum += tmp;
            maxn = max(maxn,tmp);
        }

        printf("%d\n",max(maxn,sum/m + !!(sum%m)));
    }
}