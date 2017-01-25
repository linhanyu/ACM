//
// Created by Henry on 17/1/18.
//

#include <cstdio>
#include <cstring>
const int MAXN = 110;

char num1[MAXN],num1f[MAXN],num2[MAXN],num2f[MAXN];

void rp(char num[],char f[]){
    int cur = 0;
    int tail = strlen(num) - 1;
    while (num[cur++] != '.');
    num[cur-1] = '\0';

    while (tail >= cur && num[tail] == '0') tail--;
    int i;
    for (i = 0; cur <= tail; ++cur,++i) {
        f[i] = num[cur];
    }
    f[i] = '\0';
}


int main(){
    int cases = 0;
    while (~scanf("%s%s",num1,num2)){
        printf("Case %d: ",++cases);

        rp(num1,num1f);
        rp(num2,num2f);

        int cp = strcmp(num1,num2);
        if (cp > 0){
            puts("Bigger");
            continue;
        } else{
            if (cp < 0){
                puts("Smaller");
                continue;
            }

            cp = strcmp(num1f,num2f);

            if (cp > 0){
                puts("Bigger");
            } else if (cp < 0){
                puts("Smaller");
            } else{
                puts("Same");
            }
        }

    }
}