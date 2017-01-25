//
// Created by Henry on 17/1/22.
//

#include <cstdio>
#include <memory.h>
typedef long long LL;

const int cost[] = {6,2,5,5,4,5,6,3,7,6};

char str[50];
int home[3],guest[3],h,m,s,th,tm,ts;

LL ans;

void init(){
    memset(home,0, sizeof(home));
    memset(guest,0, sizeof(guest));
    ans = 0;
}

void dealG(int A[],int size){
    int g = 0;
    for (int i = 0; i < size; ++i) {
        A[i] += g;
        g = A[i]/10;
        A[i] %= 10;
    }
}

int main(){
    int cases = 0;
    while (~scanf("%s",str)){
        init();
        printf("Case %d: ",++cases);

        scanf("%d:%d:%d",&h,&m,&s);

        while (scanf("%s",str) && str[0] != 'E'){
            th = h;
            tm = m;
            ts = s;
            scanf("%d:%d:%d",&h,&m,&s);
            LL ct,pt;
            pt = th*3600 + tm*60 + ts;
            ct = h*3600 + m*60 + s;
            long long fac = 0;

            bool flg = true;
            for (int i = 2; i >= 1; --i) {
                if (flg && home[i] == 0)
                    continue;
                flg = false;
                fac += cost[home[i]];
            }

            flg = true;
            for (int i = 2; i >= 1; --i) {
                if (flg && guest[i] == 0) continue;
                flg = false;
                fac += cost[guest[i]];
            }

            fac += cost[home[0]] + cost[guest[0]];
            ans += (ct-pt)*fac;

            long long step;
            scanf("%s%lld",str,&step);
            if (str[0] == 'h'){
                home[0] += step;
                dealG(home,3);
            } else{
                guest[0] += step;
                dealG(guest,3);
            }
        }

        th = h;
        tm = m;
        ts = s;
        scanf("%d:%d:%d",&th,&tm,&ts);
        LL ct,pt;
        ct = th*3600 + tm*60 + ts;
        pt = h*3600 + m*60 + s;
        long long fac = 0;

        bool flg = true;
        for (int i = 2; i >= 1; --i) {
            if (flg && home[i] == 0) continue;
            flg = false;
            fac += cost[home[i]];
        }
        flg = true;
        for (int i = 2; i >= 1; --i) {
            if (flg && guest[i] == 0) continue;
            flg = false;
            fac += cost[guest[i]];
        }

        fac += cost[home[0]] + cost[guest[0]];

        ans += (ct-pt)*fac;

        printf("%lld\n",ans);

    }
}