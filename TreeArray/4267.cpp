//
// Created by Henry on 16/11/23.
//
#include <cstdio>
#include <memory.h>

#define Lowbit(x) (x&-x)

using namespace std;

const int MAXN = 50010;
int cnt[MAXN][11][11];
int num[MAXN];
int n;

void add(int pos,int k,int mod,int val){
    while (pos){
        cnt[pos][k][mod] += val;
        pos -= Lowbit(pos);
    }
}

int sum(int pos,int a){
    int s = 0;
    while (pos < MAXN){
        for (int i = 1; i <= 10 ; ++i) {
            s += cnt[pos][i][a%i];
        }
        pos += Lowbit(pos);
    }

    return s;
}

void init(){
    memset(cnt,0, sizeof(cnt));
}

int main(){
    while (~scanf("%d",&n)){
        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&num[i]);
        }

        int m;
        scanf("%d",&m);
        while (m--){
            int op;
            scanf("%d",&op);
            if (op == 1){
                int a,b,k,adder;
                scanf("%d%d%d%d",&a,&b,&k,&adder);
                add(b,k,a%k,adder);
                add(a-1,k,a%k,-adder);
            }else{
                int pos;
                scanf("%d",&pos);
                printf("%d\n",num[pos] + sum(pos,pos));
            }
        }
    }

}
