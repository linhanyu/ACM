//
// Created by Henry on 16/12/13.
//
#include <cstdio>
#include <memory.h>

const int MAXN = 500 + 10;

struct node{
    int index;
    char ch;
}ans[MAXN<<1];

int n,cur;

bool r[MAXN],c[MAXN];

char Map[MAXN][MAXN];
//.覆盖过
void init(){
    memset(r,0, sizeof(r));
    memset(c,0, sizeof(c));
    cur = 0;
}

bool unFinish(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (Map[i][j] != '.') return true;
        }
    }
    return false;
}

void pushans(char ch,int idx){
    ans[cur].index = idx;
    ans[cur].ch = ch;
    cur++;
}

bool find(){
    for (int i = n-1; i >= 0 ; --i) {
        if (r[i]) continue;

        int t = 0,j;
        for (j = 0; j < n; ++j) {
            if (Map[i][j] == 'O') break;
            else if (Map[i][j] == '.') t++;
        }

        if (t == n){
            r[i] = true;
            continue;
        }

        if (j == n){
            //全是X
            r[i] = true;
            pushans('R',i+1);
            for (int k = 0; k < n; ++k) Map[i][k] = '.';

            return true;
        }
    }

    for (int i = n-1; i >= 0 ; --i) {
        if (c[i]) continue;

        int t = 0,j;
        for (j = 0; j < n; ++j) {
            if (Map[j][i] == 'X') break;
            else if (Map[j][i] == '.') t++;
        }

        if (t == n){
            c[i] = true;
            continue;
        }

        if (j == n){
            //全是X
            c[i] = true;
            pushans('C',i+1);
            for (int k = 0; k < n; ++k) Map[k][i] = '.';

            return true;
        }
    }

    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();

        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%s",Map[i]);
        }

        bool flag = true;

        while (unFinish()){
            if (!find()){
                flag = false;
                break;
            }
        }

        if (flag){
            for (int i = cur-1; i >= 0 ; --i) {
                printf("%c%d%c",ans[i].ch,ans[i].index,i ? ' ':'\n');
            }
        } else{
            puts("No solution");
        }
    }
}
