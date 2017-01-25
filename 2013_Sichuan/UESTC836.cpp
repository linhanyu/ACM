//
// Created by Henry on 16/11/28.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;

const int MAXN = 1000010;

char s1[MAXN],s2[MAXN],ans[MAXN];
int fir[12],sec[12],len;

void init(){
    memset(fir,0, sizeof(fir));
    memset(sec,0, sizeof(sec));
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {


        printf("Case #%d: ",cases);

        scanf("%s %s",s1,s2);
        len = strlen(s1);

        if (len == 1){
            printf("%d\n",(s1[0] - '0' + s2[0] - '0') % 10);
            continue;
        }

        init();
        for (int i = 0; i < len; ++i) {
            fir[s1[i] - '0']++;
            sec[s2[i] - '0']++;
        }

        int x,y,Max = -1;
        for (int i = 1; i <= 9 ; ++i) {
            for (int j = 1; j <= 9 ; ++j) {
                if (fir[i] && sec[j] && (i+j)%10 > Max){
                    x = i;
                    y = j;
                    Max = (i+j)%10;
                }
            }
        }
        fir[x]--;
        sec[y]--;
        int cur = 0;
        ans[cur++] = Max + '0';


        for (int p = 9; p >=0 ; --p) {
            for (int i = 0; i <= 9 ; ++i) {
                if (fir[i]){
                    int j = p >= i ? p-i : p + 10 - i;
                    if (j > 9) continue;
                    int k = min(fir[i],sec[j]);
                    fir[i] -= k;
                    sec[j] -= k;
                    while (k--) ans[cur++] = p + '0';
                }
            }
        }
        ans[cur] = '\0';
        int s = 0;
        while (s < len-1 && ans[s] == '0') s++;

        printf("%s\n",ans + s);

    }
}