//
// Created by Henry on 16/12/11.
//

#include <cstdio>

typedef long long LL;

int n,m,t;

int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&m);
        LL c,s;
        c = s = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d",&tmp);
            c += tmp;
        }

        for (int i = 0; i < m; ++i) {
            int tmp;
            scanf("%d",&tmp);
            s += tmp;
        }

        if (c == s){
            puts("Draw");
        } else{
            puts( c > s ? "Calem" : "Serena");
        }
    }
}