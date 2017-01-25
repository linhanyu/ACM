//
// Created by Henry on 16/11/9.
//

#include <cstdio>
#include <memory.h>
using namespace std;

const int MAXN = 25;

int sg[MAXN],stone[MAXN];

bool vis[MAXN];

int getSg(int k){
    memset(vis,0, sizeof(vis));

    for (int i = 0; i < k; ++i) {
        for (int j = i; j < k; ++j) {
            int p = sg[i] ^ sg[j];
            vis[p] = true;
        }
    }

    for (int i = 0; ; ++i) {
        if (!vis[i]) return i;
    }
}

void init(){
    sg[0] = 0;
    for (int i = 1; i < 24; ++i) {
        sg[i]  = getSg(i);
    }
}

int main(){
    init();
    int n;
    while (~scanf("%d",&n) && n){
        for (int i = 0; i < n; ++i) {
            scanf("%d",&stone[i]);
        }

        int now = 0;
        for (int i = 0; i < n; ++i) {
            if (stone[i] & 1) now ^= sg[n-i-1];
        }
    }
}