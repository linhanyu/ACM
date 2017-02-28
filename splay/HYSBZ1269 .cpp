////
//// Created by Henry on 17/2/20.
////




#include <cstdio>
#include <algorithm>

using namespace std;


#define Key_Value ch[ch[root][1]][0]
#define MID (l+r)>>1
const int MAXN = 2*1024*1024+10;

char key[MAXN];
int rev[MAXN];
int s[MAXN],ch[MAXN][2],pre[MAXN],siz[MAXN];
int tot1,tot2,root;
char A[MAXN];


void updateRev(int rt){
    if (!rt)return;
    swap(ch[rt][0],ch[rt][1]);
    rev[rt] ^= 1;
}

void pushDown(int rt){
    if (rev[rt]){
        updateRev(ch[rt][0]);
        updateRev(ch[rt][1]);
        rev[rt] = 0;
    }
}

void pushUp(int rt){
    siz[rt] = 1;
    if (ch[rt][0]) siz[rt] += siz[ch[rt][0]];
    if (ch[rt][1]) siz[rt] += siz[ch[rt][1]];
}

int getKth(int k,int rt){
    pushDown(rt);
    int t = siz[ch[rt][0]] + 1;
    if (k == t) return rt;
    if (k < t) return getKth(k,ch[rt][0]);
    return getKth(k - t,ch[rt][1]);
}


void prt(){
    for (int i = 2; i <= 20; ++i) {
        printf("%c",key[getKth(i,root)]);
    }
    puts("");
}

void newNode(char k,int & rt,int fa){
    if (tot2) rt = s[tot2--];
    else rt = ++tot1;
    key[rt] = k;
    ch[rt][0] = ch[rt][1] = 0;
    rev[rt] = 0;
    pre[rt] = fa;
    siz[rt] = 1;
}

void Build(int l,int r,int & rt,int fa){
    if (l > r) return;
    int mid = MID;
    newNode(A[mid],rt,fa);
    Build(l , mid - 1,ch[rt][0],rt);
    Build(mid + 1, r ,ch[rt][1],rt);
    pushUp(rt);
}

void Rotate(int rt,int kind){
    int y = pre[rt];
    pushDown(y);
    pushDown(rt);

    ch[y][!kind] = ch[rt][kind];
    pre[ch[rt][kind]] = y;

    if (pre[y]) ch[pre[y]][ch[pre[y]][1] == y] = rt;
    pre[rt] = pre[y];
    ch[rt][kind] = y;
    pre[y] = rt;
    pushUp(y);
}

void Splay(int rt,int goal){
    pushDown(rt);
    while (pre[rt] != goal){
        if (pre[pre[rt]] == goal){
            Rotate(rt,ch[pre[rt]][0] == rt);
        } else{
            pushDown(pre[pre[rt]]);
            pushDown(pre[rt]);
            pushDown(rt);

            int y = pre[rt];
            int kind = ch[pre[y]][0] == y;
            if (ch[y][kind] == rt){
                Rotate(rt,!kind);
                Rotate(rt,kind);
            } else{
                Rotate(y,kind);
                Rotate(rt,kind);
            }
        }
    }
    pushUp(rt);
    if(goal == 0) root = rt;
}



void Insert(int pos,int L,int R){
    Splay(getKth(pos + 1,root),0);
    Splay(getKth(pos + 2,root),root);
    Build(L,R,Key_Value,ch[root][1]);
    pushUp(ch[root][1]);
    pushUp(root);
}

int getMin(int rt){
    while (ch[rt][0]) rt = ch[rt][0];
    return rt;
}

int getNext(int rt){
    return ch[rt][1] ? getMin(rt) : -1;
}

void Reverse(int pos,int n){
    Splay(getKth(pos + 1,root),0);
    Splay(getKth(pos + n + 2,root),root);
    updateRev(Key_Value);
    pushUp(ch[root][1]);
    pushUp(root);
}

void Erase(int rt){
    if (!rt)return;
    s[++tot2] = rt;
    Erase(ch[rt][1]);
    Erase(ch[rt][0]);
}

void Delete(int pos,int n){
    Splay(getKth(pos + 1 ,root),0);
    Splay(getKth(pos + n + 2,root),root);
    Erase(Key_Value);
    pre[Key_Value] = 0;
    Key_Value = 0;
    pushUp(ch[root][1]);
    pushUp(root);
}

int Get(int pos){
    Splay(getKth(pos+2 ,root),0);
    return root;
}
void initSplay(){
    root = tot2 = tot1 = 0;
    ch[root][0] = ch[root][1] = siz[root] = pre[root] = rev[root] = 0;
    newNode('\0',root,0);
    newNode('\0',ch[root][1],root);
    pushUp(ch[root][1]);
    pushUp(root);
}

char str[MAXN],op[100];




int main(){
    int n,cur,k,s;
    while (~scanf("%d",&n)){
        initSplay();
        cur = 0;
        while (n--){
            scanf("%s",op);

            switch (op[0]) {
                case 'M':
                    scanf("%d",&cur);
                    break;
                case 'I':
                    scanf("%d",&k);
                    getchar();
                    gets(A);
                    Insert(cur,0,k-1);
                    break;
                case 'D':
                    scanf("%d",&k);
                    Delete(cur,k);
                    break;
                case 'R':
                    scanf("%d",&k);
                    Reverse(cur,k);
                    break;
                case 'G':
                    printf("%c\n",key[Get(cur)]);
                    break;
                case 'P':
                    cur--;
                    break;
                case 'N':
                    cur++;
                    break;
            }
        }
    }
}