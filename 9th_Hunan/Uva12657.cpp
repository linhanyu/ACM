//
// Created by Henry on 17/1/27.
//
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;



int l[MAXN],r[MAXN];

void add(int u,int v){
    l[v] = u;
    r[u] = v;
}

int main(){
    int m,n,cases = 0;
    while (~scanf("%d%d",&n,&m)){
        for (int i = 1; i <= n ; ++i) {
            l[i] = i-1;
            r[i] = i+1;
        }
        r[n] = 0;
        r[0] = 1;
        l[0] = n;

        bool rev = 0;
        while (m--){
            int op;
            scanf("%d",&op);
            if (op == 4){
                rev = !rev;
            } else{
                int x,y;
                scanf("%d%d",&x,&y);

                if (op == 3 && r[y] == x){
                    swap(x,y);
                }if(op!=3&&rev)
                    op=3-op;
                if(op==1&&l[y]==x)
                    continue;
                if(op==2&&r[y]==x)
                    continue;

                int lx=l[x],rx=r[x],ly=l[y],ry=r[y];
                if (op == 1){
                    add(lx,rx);
                    add(ly,x);
                    add(x,ry);
                } else if (op == 2){
                    add(lx,rx);
                    add(y,x);
                    add(x,ry);
                } else{
                    if(r[x]==y)
                        add(lx,y),add(y,x),add(x,ry);
                    else
                        add(lx,y),add(y,rx),add(ly,x),add(x,ry);
                }
            }


        }
        int k=0;
        long long ans=0;
        for(int i=1;i<=n;++i){
            k=r[k];
            if(i&1)
                ans+=k;
        }
        if(rev&&!(n&1))
            ans=(long long)n/2*(n+1)-ans;
        printf("Case %d: %lld\n",++cases,ans);
    }
}

