//
// Created by Henry on 16/11/22.
//
#include <cstdio>
#include <set>
#define lowbit(x) (x&-x)

typedef long long LL;

using namespace std;

const int MAXN = 30001;

set<LL > st;
LL A[MAXN];

int t,n,q;

void add(int status,LL val){
    while (status <= n){
        A[status] += val;
        status += lowbit(status);
    }
}


int main(){


    A[0] = 0;
    scanf("%d",&t);
    while (t--){
        memset(A,0, sizeof(A));
        st.clear();

        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld",&A[i]);
            if (st.count(A[i]) == 0){
                add(i,A[i]);
                st.insert(A[i]);
            }



        }

        scanf("%d",&q);

        while (q--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%lld\n",A[b] - A[a-1]);
        }
    }
}
