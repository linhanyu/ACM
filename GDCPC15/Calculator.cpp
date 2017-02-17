//
// Created by Henry on 17/2/8.
//

#include <cstdio>
#include <cstring>
const int MAXN = 50000 + 10;
const int MOD = 29393;

char op[MAXN][30];

int n,m;

int fpow(int base,int p){
    int ans = 1;
    while (p){
        if (p & 1){
            ans = ans*base%MOD;
        }

        base = base*base%MOD;
        p>>=1;
    }
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d:\n",cases);

        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; ++i) scanf("%s",op[i]);

        while (m--){
            int tp;
            scanf("%d",&tp);
            if (tp == 1){
                int x;
                scanf("%d",&x);
                int tmp ;

                for (int i = 1; i <= n; ++i) {
                    sscanf(op[i] + 1,"%d",&tmp);
                    if (op[i][0] == '*'){
                        x = x*tmp%MOD;
                    } else if (op[i][0] == '+'){
                        x = (x+tmp)%MOD;
                    } else{
                        x = fpow(x,tmp);
                    }
                }

                printf("%d\n",x);
            } else{
                int pos;
                scanf("%d",&pos);
                scanf("%s",op[pos]);
            }
        }
    }
}