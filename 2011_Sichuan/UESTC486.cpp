//
// Created by Henry on 17/2/5.
//

#include <cstdio>
#include <memory.h>
#include <cstring>
#include <algorithm>

using namespace std;

char alpha[] = {'g','d','m','r','i'};
int cnt[27];
//1g 1d 1m 1r 1i 2n 3o
char str[1000 + 10];
void init(){
    memset(cnt,0, sizeof(cnt));
}
int main(){
    int t;

    scanf("%d",&t);
    getchar();
    for (int cases = 1; cases <= t; ++cases) {
        init();

        printf("Case #%d: ",cases);
        gets(str);

        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (str[i] == ' ')cnt[26]++;
            else cnt[str[i] - 'a']++;
        }

        int Min = 1010;
        for (int i = 0; i < 5; ++i) {
            Min = min(Min,cnt[alpha[i] - 'a']);
        }

//        Min = min(Min,cnt[26]);
        Min = min(Min,cnt['n' - 'a']/2);
        Min = min(Min,cnt['o' - 'a']/3);

        printf("%d\n",Min);
    }
}