//
// Created by Henry on 16/9/9.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include <queue>
const int MAXN = 101;

using namespace std;

int glass[2];
int room[2];
//vector<int> op;

void fill(int i){
    glass[i] = room[i];
}

void drop(int i){
    glass[i] = 0;
}

void pour(int i,int j){
    if(glass[i] > room[j] - glass[j]){
        glass[i] -= room[j] - glass[j];
        fill(j);

    }else{
        glass[j] += glass[i];
        drop(i);
    }
}

bool vis[MAXN][MAXN];
int c;

struct status{
    int glass[2];
}st[MAXN*MAXN];

int anchor[MAXN*MAXN];
int cur;
queue<int> Q;

void clearQ(){
    while (!Q.empty()){
        Q.pop();
    }
}

void addstatus(int preanchor,int g1,int g2){
    st[cur].glass[0] = g1;
    st[cur].glass[1] = g2;
    anchor[cur++] = preanchor;

}

int prei[MAXN],prej[MAXN],op[MAXN][MAXN];
int finalanchor;
bool bfs() {
    clearQ();
    Q.push(0);
    cur = 1;

    while (!Q.empty()) {
        int source = Q.front();
        Q.pop();

        glass[0] = st[source].glass[0];
        glass[1] = st[source].glass[1];


        if (st[source].glass[0] == c || st[source].glass[1] == c) {
            finalanchor = source;
            return true;
        }



        for (int i = 0; i < 2; i++) {
            fill(i);
            if (!vis[glass[0]][glass[1]]) {
                vis[glass[0]][glass[1]] = true;
                Q.push(cur);
                addstatus(source,glass[0],glass[1]);

                op[glass[0]][glass[1]] = i;
            }
            glass[i] = st[source].glass[i];

            drop(i);
            if (!vis[glass[0]][glass[1]]) {
                vis[glass[0]][glass[1]] = true;
                Q.push(cur);
                addstatus(source,glass[0],glass[1]);
                op[glass[0]][glass[1]] = i+2;
            }
            glass[i] = st[source].glass[i];

            pour(i, !i);
            if (!vis[glass[0]][glass[1]]) {
                vis[glass[0]][glass[1]] = true;
                Q.push(cur);
                addstatus(source,glass[0],glass[1]);
                op[glass[0]][glass[1]] = i+4;
            }
            glass[0] = st[source].glass[0];
            glass[1] = st[source].glass[1];

        }




    }
    return false;
}
//
//bool dfs(){
//
//    if(glass[0] == c || glass[1] == c){
//        return true;
//    }
//
//    vis[glass[0]][glass[1]] = true;
//
//    int pre[2];
//    pre[0] = glass[0];
//    pre[1] = glass[1];
//
//     for(int i=0;i<2;i++){
//
//        fill(i);
//        if(!vis[glass[0]][glass[1]] && dfs()){
//            op.push_back(i+0);
//            return true;
//        }
//        glass[i] = pre[i];
//
//    }
//
//    for(int i=0;i<2;i++){
//
//        drop(i);
//        if(!vis[glass[0]][glass[1]] && dfs()){
//            op.push_back(i+2);
//            return true;
//        }
//
//        glass[i] = pre[i];
//
//    }
//
//     for(int i=0;i<2;i++){
//
//        pour(i,!i);
//         if(!vis[glass[0]][glass[1]] && dfs()){
//             op.push_back(i+4);
//             return true;
//         }
//        glass[0] = pre[0];
//        glass[1] = pre[1];
//
//
//    }
//
//    return false;
//
//
//}
int counter;
void prtans(int a){
    if (anchor[a] == -1){
        printf("%d\n",counter);
        return;
    }

    counter++;
    prtans(anchor[a]);
    switch (op[st[a].glass[0]][st[a].glass[1]]){
        case 0:
            puts("FILL(1)");
            break;
        case 1:
            puts("FILL(2)");
            break;
        case 2:
            puts("DROP(1)");
            break;
        case 3:
            puts("DROP(2)");
            break;
        case 4:
            puts("POUR(1,2)");
            break;
        case 5:
            puts("POUR(2,1)");
            break;
    }

}

//int main(){
//    st[0].glass[0] = st[0].glass[1] = 0;
//    anchor[0] = -1;
//    while(cin>>room[0]>>room[1]>>c){
//        glass[0] = glass[1] = 0;
//
//        for(int i=0;i<=room[0];i++){
//            for(int j=0;j<=room[1];j++){
//                vis[i][j] = false;
//
//            }
//        }
//
//        vis[0][0] = true;
//
//
//        counter = 0;
//        if(bfs()){
//            prtans(finalanchor);
//        }else{
//            puts("impossible");
//        }
//    }
//
//}
#include<stdio.h>
int sumab(int x,int y);
int main()
{int a,b,sum;
    printf("请输入变量a与b的值：");
    scanf("%d %d",&a,&b);
    sum=sumab(a,b);
    printf("a与b的和等于%d",sum);
    return 0;
}