//
// Created by Henry on 17/1/25.
//

#include <cstdio>
#include <memory.h>

const int MAXN = 13;
const int MAXT = 110;

bool ACed[MAXT][MAXN];
int Team[MAXN],Time[MAXN];

void add(int time,int team,int pb){
    if (ACed[team][pb])return;
        ACed[team][pb] = true;
        Team[pb] = team;
        Time[pb] = time;
}

void init(){
    memset(ACed,0, sizeof(ACed));
    memset(Team,-1, sizeof(Team));
}

int main(){
    int n,t,m;
    while (~scanf("%d%d%d",&n,&t,&m)){
        init();
        while (m--){
            int time,team;
            char pb[10],statu[10];

            scanf("%d %d %s %s",&time,&team,pb,statu);
            if (statu[0] == 'Y') add(time,team,(int)pb[0] - 'A');
        }

        for (int i = 0; i < n; ++i) {
            if (~Team[i]){
                printf("%c %d %d\n",i + 'A',Time[i],Team[i]);
            } else{
                printf("%c - -\n",i + 'A');
            }
        }
    }
}