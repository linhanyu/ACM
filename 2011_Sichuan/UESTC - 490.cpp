//
// Created by Henry on 17/2/6.
//

#include<cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int C[2];

char str[MAXN];

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);
        scanf("%s",str);
        memset(C,0, sizeof(C));

        int len = strlen(str);
        int invSum = 0;
        int b1 = len>>1,b2 = len - b1;

        for (int i = 0; i < b1; ++i) {
            if (str[i] == 'R') C[0]++;
            else invSum += C[0];
        }

        for (int i = b2; i < len; ++i) {
            if (str[i] == 'B') C[1]++;
            else invSum += C[1];
        }

        int best = invSum;
        for (int i = 0; i < len; ++i) {
            int t = (b1+i)%len;
            if (str[t] == 'B') {
                invSum -= b2 - C[1];
                invSum += C[0] - (str[i] == 'R');
            }
            if(str[i] == 'R' ) { invSum -= b1-C[0]; invSum += C[1] - (str[t] == 'B'); }
            if(str[t] == 'B') C[1]--;
            else C[0]++;
            if(str[i] == 'R') C[0]--;
            else C[1]++;
            best = min(invSum,best);
        }

        printf("%d\n",best);

    }

}