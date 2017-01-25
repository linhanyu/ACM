//
// Created by Henry on 16/8/21.
//

#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <memory>

#define NUM1 27
#define NUM2 1010
#define ToInt(a) (a-'a'+1)
#define ABS(a) ((a) > 0 ? (a):(-a))

using namespace std;

int UFSet[NUM1];
int In[NUM1],Out[NUM2];
bool Appear[NUM1];

int Find(int root){
    if (UFSet[root] <= 0){
        return root;
    } else{
        return UFSet[root] = Find(UFSet[root]);
    }
}

void Merge(int root1,int root2){
    root1 = Find(root1);
    root2 = Find(root2);

    if (root1 == root2){
        return;
    }

    if (UFSet[root1] < UFSet[root2]){
        //阶为负数.值小则绝对值大,阶大
        UFSet[root2] = root1;

    } else{
        if (UFSet[root1] == UFSet[root2]){
            UFSet[root2]--;
        }

        UFSet[root1] = root2;
    }
}

//void initSet(){
//
//}

//void initrls(){
//    for (int i = 0; i < NUM1; ++i) {
//        rls[i].clear();
//    }
//}

bool JudgeConnected(){
    bool flag = false;
    int preRoot = -1;
    for (int i = 1; i < NUM1; ++i) {
        if (Appear[i] ) {
            int root = Find(i);
            if (flag && preRoot != root){
                return false;
            }
            flag = true;
            preRoot = root;
        }


    }

    return true;
}



bool IsOla(){
    int count = 0;

    for (int i = 1; i < NUM1; ++i) {

        if (Appear[i]){
            if (In[i] == Out[i]){
                continue;
            } else{
                if(ABS(In[i] - Out[i]) > 1 || count > 2){
                    return false;
                } else{
                    count ++ ;
                }
            }
        }
    }

    return true;
}

int main(){
    int cases,n;
    char tmpSeq[NUM2];

    cin>>cases;

    while(cases--){
        cin>>n;
        memset(In,0, sizeof(In));
        memset(Out,0, sizeof(Out));
        memset(UFSet,0, sizeof(UFSet));
        memset(Appear,0, sizeof(Appear));

        for (int i = 0; i < n; ++i) {
            cin>>tmpSeq;
            int Len = strlen(tmpSeq);
            int a = ToInt(tmpSeq[0]),b = ToInt(tmpSeq[Len-1]);
            Out[a]++;
            In[b]++;
            Appear[a] = Appear[b] = true;
            Merge(a,b);
        }

        if (JudgeConnected() && IsOla()){
            printf("Ordering is possible.\n");

        } else{
            printf("The door cannot be opened.\n");
        }

    }
}