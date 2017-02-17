//
// Created by Henry on 17/2/5.
//

#include <cstdio>

#define L pos<<1
#define R pos<<1|1

struct node{
    bool Maxheap,Minheap,LBST,RBST;
    node(bool h1,bool h2,bool b1,bool b2):Minheap(h1),Maxheap(h2),LBST(b1),RBST(b2){}
};

const int MAXN = 10010;
int n,A[MAXN];

bool inbound(int pos){
    return pos <= n;
}

node dfs(int pos){

    if (!inbound(pos)){
        return node(true, true, true, true);
    }

    node l = dfs(L);
    if (!l.Minheap && !l.LBST && !l.RBST && !l.Maxheap)
        return node(false, false, false, false);
    node r = dfs(R);
    if (!r.Minheap && !r.LBST && !r.RBST && !r.Maxheap)
        return node(false, false, false, false);
    node ans(false, false, false, false);

    if (l.Maxheap && r.Maxheap){
        if (inbound(L) && inbound(R)){
            ans.Maxheap = A[pos] > A[L] && A[pos] > A[R];
        } else if (inbound(L)){
            ans.Maxheap = A[pos] > A[L];
        } else if (inbound(R)){
            ans.Maxheap = A[pos] > A[R];
        } else{
            ans.Maxheap = true;
        }
    }

    if (l.Minheap && r.Minheap){
        if (inbound(L) && inbound(R)){
            ans.Minheap = A[pos] < A[L] && A[pos] < A[R];
        } else if (inbound(L)){
            ans.Minheap = A[pos] < A[L];
        } else if (inbound(R)){
            ans.Minheap = A[pos] < A[R];
        } else{
            ans.Minheap = true;
        }
    }

    if (l.LBST && r.LBST){
        if (inbound(L) && inbound(R)){
            ans.LBST = A[pos] > A[L] && A[pos] < A[R];
        } else if (inbound(L)){
            ans.LBST = A[pos] > A[L];
        } else if (inbound(R)){
            ans.LBST = A[pos] < A[R];
        } else{
            ans.LBST = true;
        }
    }

    if (l.RBST && r.RBST){
        if (inbound(L) && inbound(R)){
            ans.RBST = A[pos] < A[L] && A[pos] > A[R];
        } else if (inbound(L)){
            ans.RBST = A[pos] < A[L];
        } else if (inbound(R)){
            ans.RBST = A[pos] > A[R];
        } else{
            ans.RBST = true;
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d: ",cases);

        scanf("%d",&n);
        for (int i = 1; i <=n ; ++i) scanf("%d",&A[i]);

        node ans = dfs(1);
        if ((ans.Maxheap || ans.Minheap) && (ans.LBST || ans.RBST)){
            puts("Both");
        } else if (ans.Maxheap || ans.Minheap){
            puts("Heap");
        } else if (ans.LBST || ans.RBST){
            puts("BST");
        } else{
            puts("Neither");
        }
    }
}