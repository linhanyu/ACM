//
// Created by Henry on 16/7/12.
//
#include <cstdio>
#include <algorithm>
#include <cmath>

#define NUM_1 20011
#define NUM_2 10000
#define l_s(a) (a<<1)
#define r_s(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define ABS(a) ((a)>0?(a):-(a))
using namespace std;

struct Seg{
    int l,r,h;
    int s;
    void set(int a,int b,int c,int d){
        l=a;
        r=b;
        h=c;
        s=d;
    }

    bool operator < (const Seg & sg) const {
        if (h == sg.h) return s>sg.s;
        else return h<sg.h;
    }
}ss[NUM_1];

int cnt[NUM_1<<2];
int len[NUM_1<<2];
bool lbd[NUM_1<<2] , rbd[NUM_1<<2];
int numseg[NUM_1<<2];

void PushUp(int l,int r,int rt){
    if (cnt[rt]){
        lbd[rt] = rbd[rt] = true;
        len[rt] = r-l+1;
        numseg[rt] = 2;
    } else if(l==r){
        len[rt] = numseg[rt] = lbd[rt] = rbd[rt] = 0;
    } else{
        lbd[rt] = lbd[l_s(rt)];
        rbd[rt] = rbd[r_s(rt)];
        len[rt] = len[l_s(rt)] + len[r_s(rt)];
        numseg[rt] = numseg[l_s(rt)] + numseg[r_s(rt)];
        if (lbd[r_s(rt)] && rbd[l_s(rt)]) numseg[rt] -= 2;
    }
}

void update(int L,int R,int l,int r,int c,int rt){
    if (L<= l && r<= R){
        cnt[rt] += c;
        PushUp(l,r,rt);
        return;
    }

    int m = MID(l,r);
    if (L<= m) update(L,R,l,m,c,l_s(rt));
    if (R > m) update(L,R,m+1,r,c,r_s(rt));

    PushUp(l,r,rt);
}


int main(){
    int n;
    while (~scanf("%d",&n)){
        int m=0;
        int l_bd=NUM_2,r_bd = -NUM_2;
        for (int i = 0; i < n; ++i) {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            l_bd = min(l_bd,a);
            r_bd = max(r_bd,c);
            ss[m++].set(a,c,b,1);
            ss[m++].set(a,c,d,-1);
            //下1上-1
        }

        sort(ss,ss+m);
        int ret=0,last=0;

        for (int i = 0; i < m; ++i) {
            if (ss[i].l < ss[i].r) {
                update(ss[i].l,ss[i].r-1,l_bd,r_bd-1,ss[i].s,1);
            }

            ret += numseg[1] * (ss[i+1].h - ss[i].h);
            ret += ABS(len[1] - last);
            last = len[1];
        }

        printf("%d\n",ret);

    }

}

