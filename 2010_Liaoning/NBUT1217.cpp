//
// Created by Henry on 17/2/5.
//

#include <cstdio>
#include <cstring>

char str[][20] = {"bowl", "knife", "fork","chopsticks"};
char tmp[100000];

int main(){
    int n;
    while (~scanf("%d",&n)){
        bool flg = false;
        for (int i = 0; i < n; ++i) {
            scanf("%s",tmp);
            for (int j = 0; j < 4; ++j) {
                if (strcmp(str[j],tmp)) continue;

                if (flg) printf(" ");
                flg = true;
                printf("%s",str[j]);
            }
        }

        puts("");
    }
}