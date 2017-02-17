//
// Created by Henry on 17/2/8.
//

#include<cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 100000 + 10;

struct cs{
    LL r,e,l;

    bool operator<(const cs & c) const {
        return e < c.e;
    }
}G[MAXN];

int n;

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d: ",cases);
        scanf("%d",&n);

        for (int i = 0; i < n; ++i) scanf("%d%d%d",&G[i].r,&G[i].e,&G[i].l);

        LL cur = 0,now = 0;
        sort(G,G+n);

        bool flg = true;
        for (int i = 0; i < n; ++i) {
            LL res = G[i].e - cur;
            if (res < 0) {
                flg = false;
                break;
            }

            while (now < n && res){
                if (G[now].r <= res) res -= G[now++].r;
                else G[now].r -= res,res = 0;
            }

            if (now <= i){
                flg = false;
                break;
            }
            cur = G[i].l + G[i].e;
        }

        puts(flg ? "YES":"NO");

    }
}