//
// Created by Henry on 16/11/29.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>

#define LowBit(x) (x&-x)

using namespace std;

const int MAXN = 505;
const int MAXX = MAXN*MAXN;
int n,m,r,q,cnt,cur;
int food[MAXN][MAXN],prod[MAXN][MAXN],a[MAXX],b[MAXX],x[MAXX],s[MAXX];


void add(int pos,int val){
    while (pos <= cnt){
        s[pos] = max(s[pos],val);
        pos += LowBit(pos);
    }
}
int query(int pos){
    int res = 0;
    while (pos){
        res = max(res,s[pos]);
        pos -= LowBit(pos);
    }
    return res;
}

void init(){
    memset(food,0, sizeof(food));
    memset(prod,0, sizeof(prod));
    memset(s,0, sizeof(s));
}

void MatrixCompress(int A[][MAXN]){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d",&A[i][j]);
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }
}


int main(){
    int t,ans;
    scanf("%d",&t);

    for (int cases = 1; cases <= t; ++cases) {
        init();

        printf ("Case #%d:\n" , cases);

        scanf("%d%d%d%d",&n,&m,&r,&q);

        MatrixCompress(food);
        MatrixCompress(prod);

        cur = 0;
        r = 2 * r + 1;

        for (int i = r; i <= n ; ++i) {
            for (int j = r; j <= m; ++j) {
                //离散化
                a[cur] = food[i][j] - food[i-r][j] - food[i][j-r] + food[i-r][j-r];
                b[cur] = prod[i][j] - prod[i-r][j] - prod[i][j-r] + prod[i-r][j-r];
                x[cur] = a[cur];
                cur ++;
            }
        }

        sort(x,x+cur);
        cnt = unique(x,x+cur) - x;
        //去重后返回尾地址,inclusive
        for (int i = 0; i < cur; ++i) {
            int y = cnt - (lower_bound(x,x+cnt,a[i]) - x);
            add(y,b[i]);
        }


        while (q--){
            int A,B;
            scanf("%d%d",&A,&B);

            int low = min(A,B) + r * r * 1;
            int high = min(A,B) + r * r * 3;

            while (low <= high){
                int mid = (low + high) >> 1;
                int y = cnt - (lower_bound (x , x + cnt , mid - A) - x);
                if (y < 1) {
                    high = mid - 1;
                    continue;
                }

                int tmp = query(y);
                if(tmp + B >= mid){
                    ans = mid;
                    low = mid+1;
                } else{
                    high = mid - 1;
                }
            }

            printf("%d\n",ans);
        }

        if (cases != t) puts ("");

    }
}