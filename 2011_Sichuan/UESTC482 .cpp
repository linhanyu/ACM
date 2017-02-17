//
// Created by Henry on 17/2/5.
//

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>

typedef long long LL;

using namespace std;

const int MAXN = 100000 + 10;
const int MAXM = 100 + 20;
const int INF = 0x3f3f3f3f;

struct thing{
    LL v,r,c;
}A[MAXN];

struct node{
    LL t,m;
    bool operator<(const node & n) const {
        return t > n.t;
    }
};

LL n,m;

bool cmp(const thing & a,const thing & b){
//    if(a.v == b.v) return a.c < b.c;
    return a.r < b.r;
}



LL BFS(){
    priority_queue<node> Q;

    node tmp;
    tmp.t = 0;
    tmp.m = 1;
    Q.push(tmp);
    int i=0,st = 0;

    while (!Q.empty()){
        node s = Q.top();
        if (s.m >= m) return s.t;
        Q.pop();


        for (i = st; i <= n; ++i) {
            if (A[i].r > s.m) break;

            if (s.m >= A[i].v) continue;
            node tmp;
            tmp.m = A[i].v;
            tmp.t = A[i].c + s.t;
            Q.push(tmp);
        }

        st = i;
    }

    return -1;
}

int main(){
    int t;
    scanf("%d",&t);

    for (int cases = 1; cases <= t ; ++cases) {

        printf("Case #%d: ",cases);

        scanf("%lld%lld",&n,&m);

        for (int i = 0; i < n ; ++i) {
            scanf("%lld%lld%lld",&A[i].v,&A[i].r,&A[i].c);
        }

        sort(A , A+ n,cmp);

        printf("%lld\n",BFS());
    }
}
