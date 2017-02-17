//
// Created by Henry on 17/2/17.
//

#include <cstdio>
#include <algorithm>

using namespace std;

#define L(r) ch[r][0]
#define R(r) ch[r][1]
#define MID (l+r) >> 1
#define Key_Value ch[ch[root][1]][0]
#define GETC(x) (ch[pre[x]][1] == x)


const int MAXN = 200000 + 10;

int ch[MAXN][2],key[MAXN],pre[MAXN],siz[MAXN],a[MAXN],num[MAXN],e[MAXN],s[MAXN],node[MAXN];
int root,tot1,cnt;

void pushUp(int r){
    siz[r] = siz[L(r)] + siz[R(r)] + num[r];
}

void newNode(int & r,int fa,int k){
    r = k;
    siz[r] = e[k] - s[k] + 1;
    num[r] = e[k] - s[k] + 1;
    L(r) = R(r) = 0;
    pre[r] = fa;
}

void Build(int & x,int l,int r,int fa){
    if (l > r) return;
    int mid = MID;
    newNode(x,fa,mid);
    Build(L(x),l,mid-1,x);
    Build(R(x),mid+1,r,x);
    pushUp(x);
}

void Rotate(int x,int kind){
    int y = pre[x];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if (pre[y]) ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    pushUp(y);
}

void Splay(int r,int goal){
    while (pre[r] != goal){
        if (pre[pre[r]] == goal){
            Rotate(r,ch[pre[r]][0] == r);
        } else{
            int y = pre[r];
            int kind  = ch[pre[y]][0] == y;
            if (ch[y][kind] == r){
                Rotate(r,!kind);
                Rotate(r,kind);
            } else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    pushUp(r);
    if (goal == 0) root = r;
}

int Bin(int x,int l,int r){
    while (l<=r){
        int mid = MID;
        if (s[mid] <= x && x <= e[mid])return mid;
        if ( x < s[mid]) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int getMin(int r){
    while (L(r)){
        r = L(r);
    }
    return r;
}

void Delete(){
    if (L(root) == 0 ||  R(root)== 0){
        root = L(root) + R(root);
        pre[root] = 0;
        return;

    }

    int k = getMin(R(root));
    Splay(k,root);
    Key_Value = L(root);
    root = R(root);
    pre[L(root)] = root;
    pre[root] = 0;
    pushUp(root);
}

void Top(int x,int LB,int RB){
    int r = Bin(x,LB,RB);
    Splay(r,0);
    Delete();
    Splay(getMin(root),0);
    L(r) = 0;
    R(r) = root;
    pre[root] = r;
    root = r;
    pre[root] = 0;
    pushUp(root);
}

int Query(int x,int LB,int RB){
    int r = Bin(x,LB,RB);
    Splay(r,0);
    return siz[L(r)] + x - s[r] + 1;
}

int getRank(int r,int k){
    int t= siz[ch[r][0]];
    if (k <= t) return getRank(L(r),k);
    else if (k <= t + num[r]) return s[r] + k - t - 1;
    else return getRank(ch[r][1],k-t-num[r]);
}

void initSplay(){
    root = tot1 = 0;
    L(root) = R(root) = num[root] = siz[root] = pre[root] = 0;
    Build(root,1,cnt,0);
    pushUp(root);
}

char op[MAXN][10];
int qnum[MAXN];
int p[MAXN];

int main(){
    int n,q,t,tot2;
    scanf("%d",&t);
    for (int cases = 0; cases < t; ++cases) {
        printf("Case %d:\n",cases+1);
        tot2 = 0;
        scanf("%d%d",&n,&q);
        for (int i = 0; i < q; ++i) {
            scanf("%s%d",&op[i],&qnum[i]);
            if (op[i][0] == 'T') p[tot2++] = qnum[i];
        }

        p[tot2++] = 1;
        p[tot2++] = n;
        sort(p,p+t);
        tot2 = unique(p,p+t) - p;
        cnt = 0;

        for (int i = 0; i < t; ++i) {
            if (i && p[i] - p[i-1] > 1){
                cnt++;
                s[cnt] = p[i-1] + 1;
                e[cnt] = p[i] - 1;
            }
            cnt++;
            s[cnt] = p[i];
            e[cnt] = p[i];
        }
        initSplay();

        for (int i = 0; i < q; ++i) {
            if (op[i][0] == 'T') Top(qnum[i],1,cnt);
            else if (op[i][0] == 'Q') printf("%d\n",Query(qnum[i],1,cnt));
            else printf("%d\n",getRank(root,qnum[i]));
        }
    }
}