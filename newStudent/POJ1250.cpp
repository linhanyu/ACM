//
// Created by Henry on 17/3/5.
//

#include <cstdio>
#include <memory.h>
#define ToNum(a) (a-'A')

const int MAXN = 2000;

bool hash[30];
int main(){
    int n;
    while (~scanf("%d",&n) && n){
        char c;
        int cnt = 0,ans = 0;
        getchar();

        memset(hash,0, sizeof(hash));

        while((c = getchar()) != '\n'){
            if (hash[ToNum(c)]){
                cnt--;
                hash[ToNum(c)] = false;
            } else{
                cnt++;
                if (cnt > n) ans++;
                hash[ToNum(c)] = true;
            }
        }

        if (ans){
            printf("%d customer(s) walked away.\n",ans);
        } else{
            puts("All customers tanned successfully.");
        }
    }
}