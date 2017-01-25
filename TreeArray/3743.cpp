//
// Created by Henry on 16/11/23.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>

#define LowBit(x) (x&-x)

typedef long long LL;

using namespace std;

const int MAXN = 1000111;

struct node{
    int idx,num;

    bool operator<(const node & n) const{
        return num < n.num;
    }
};

int B[MAXN];
node num[MAXN];
LL C[MAXN];
int n;

void add(int pos,int val){
    while (pos <= n){
        C[pos] += val;
        pos += LowBit(pos);
    }
}

LL sum(int pos){
    LL ans = 0;
    while (pos) {
        ans += C[pos];
        pos -= LowBit(pos);
    }

    return ans;

}

void init(){
    memset(C,0, sizeof(C));
    memset(B,0, sizeof(B));
}


int main(){
    while (~scanf("%d",&n)){
        init();

        for (int i = 1; i <= n; ++i) {
            scanf("%d",&num[i].num);
            num[i].idx = i;
        }

        sort(num + 1,num + n + 1);

        for(int i = 1;i <= n;i++){
            //原来的位置映射到现在的位置
            B[num[i].idx] = i;
        }

        LL cnt = 0;
        for (int i = 1; i <= n; ++i) {
            add(B[i],1);
            cnt += i-sum(B[i]);


        }

        printf("%lld\n",cnt);
    }
}