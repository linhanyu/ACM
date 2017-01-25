//
// Created by Henry on 16/9/3.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

#define MAXN 10000+10
#define INF 0x7FFFFFF
using namespace std;

int inOrder[MAXN],postOrder[MAXN],Lch[MAXN],Rch[MAXN];
int n;

bool readLine(int A[]){
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss>>x) A[n++] = x;
    return n>0;
}

int build(int inOrderLeft,int inOrderRight,int postOrderLeft,int postOrderRight){
    if (inOrderLeft > inOrderRight) return 0;
    int root = postOrder[postOrderRight];
    int p = inOrderLeft;

    while(inOrder[p] != root) p++;

    int cnt = p - inOrderLeft;
    //左子树节点个数
    Lch[root] = build(inOrderLeft,p-1,postOrderLeft,postOrderLeft + cnt -1 );
    Rch[root] = build(p+1,inOrderRight,postOrderLeft + cnt,postOrderRight-1);

    return root;
}

int best,bestSum;
void dfs(int root,int sum){
    sum += root;
    if (!Lch[root] && !Rch[root]){
        if(sum < bestSum || (sum == bestSum && root < best)){
            bestSum = sum;
            best = root;
        }
    }



    if (Lch[root]) dfs(Lch[root],sum);
    if (Rch[root]) dfs(Rch[root],sum);
}

int main(){
    while(readLine(inOrder)){
        readLine(postOrder);

        build(0,n-1,0,n-1);
        bestSum = INF;
        dfs(postOrder[n-1],0);

        cout<<best<<endl;
    }
}

