//
// Created by Henry on 16/11/23.
//
#include <cstdio>
#include <memory.h>
#define Lowbit(x) (x&(-x))

using namespace std;


const int MAXT = 32001;
int n;

int Tree[MAXT+10];
int Level[MAXT+10];

void add(int pos,int val){
    while (pos <= MAXT){
        Tree[pos] += val;
        pos += Lowbit(pos);
    }
}

int sum(int pos){
    int res = 0;
    while (pos ){
        res += Tree[pos];
        pos -= Lowbit(pos);
    }

    return res;
}

void init(){
    memset(Tree,0, sizeof(Tree));
    memset(Level,0, sizeof(Level));
}

int main(){
    while(~scanf("%d",&n)){
        init();

        for (int i = 0; i < n; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            Level[sum(x+1)]++;
            add(x+1,1);
        }

        for(int i=0;i<n;i++){
            printf("%d\n",Level[i]);
        }
    }
}
