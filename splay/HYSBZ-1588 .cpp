//
// Created by Henry on 17/2/20.
//
#include <cstdio>
#include <algorithm>

#define Key_Value ch[ch[root][1]][0]

using namespace std;

const int MAXN = 100007;
const int INF = 0x3f3f3f3f;
int root;
int ch[MAXN][2],pre[MAXN],key[MAXN];
int tot1;
void newNode(int & r,int fa,int k){
    r = ++tot1;
    pre[r] = fa;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
}

void Rotate(int x,int kind){
    int y = pre[x];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if (pre[y]) ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
}

void Splay(int r,int goal){
    while (pre[r] != goal){
        if (pre[pre[r]] == goal) Rotate(r,ch[pre[r]][0] == r);
        else{
            int y = pre[r];
            int kind = ch[pre[y]][0] == y;
            if (ch[y][kind] == r){
                Rotate(r,!kind);
                Rotate(r,kind);
            } else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    if (goal == 0) root = r;
}

bool Insert(int k){
    if (!root){
        newNode(root,0,k);
        return true;
    }

    int r = root;
    while (ch[r][key[r] < k]) r = ch[r][key[r] < k];

    if (key[r] == k){
        Splay(r,0);
        return true;
    }
    newNode(ch[r][key[r] < k],r,k);
    Splay(ch[r][key[r] < k],0);
    return false;
}

int getMax(int r){
    while (ch[r][1]) r = ch[r][1];
    return key[r];
}

int getMin(int r){
    while (ch[r][0]) r = ch[r][0];
    return key[r];
}

int getPre(int r){
    return ch[r][0] ? getMax(ch[r][0]) : -1;
}

int getNext(int r){
    return ch[r][1] ? getMin(ch[r][1]) : -1;
}

void initSplay(){
    root = tot1 = 0;
}

int main(){
    int n;
    while (~scanf("%d",&n)){
        initSplay();

        int ans = 0;
        bool flg = true;
        while (n--){
            int tmp;
            scanf("%d",&tmp);

            if (Insert(tmp)){
                if (flg){
                    ans = tmp;
                    flg = false;
                }
                continue;
            }

            int pk = getPre(root);
            int nk = getNext(root);
            int tmpans = INF;
            if (~pk) tmpans = min(tmpans,tmp - pk);
            if (~nk) tmpans = min(tmpans,nk - tmp);

            ans += tmpans;
        }

        printf("%d\n",ans);
    }
}