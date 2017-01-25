//
// Created by Henry on 16/11/20.
//

#include <cstdio>
#include <cmath>
typedef long long LL;



int main(){
    int n,a;
    while (~scanf("%d",&n)){
        bool flg = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a);
            int t = sqrt(a);
            if (t*t != a) flg = false;

        }


        puts(flg ? "Yes" : "No");
    }
}