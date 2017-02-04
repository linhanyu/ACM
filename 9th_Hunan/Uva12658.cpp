//
// Created by Henry on 17/1/25.
//

#include<cstdio>

const int MAXN = 11;



int main(){
    int n;
    char screen[MAXN][50];

    scanf("%d",&n);
    for (int i = 0; i < 5; ++i) {
        scanf("%s",screen[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (screen[1][i*4 + 1] == '*') printf("1");
        else if (screen[3][i*4 + 2] != '*') printf("2");
        else printf("3");
    }

    puts("");
}