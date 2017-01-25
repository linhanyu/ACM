//
// Created by Henry on 16/12/1.
//

#include <cstdio>
#include <memory.h>
#include <queue>
#include <cstring>

#define TOINT(a) (a-'A')

using namespace std;

const int MAXE = 3000;
const int MAXV = 30;
const int offset = 30;

char ans[30],seq[10];


bool rls[MAXV][MAXV];
int In[MAXV];
int head[MAXV];

struct edge{
    int v, next;
}G[MAXE];

queue<int > Q;

int n,m;
int anscur,sign,cur;

void addedge(int u,int v){
    rls[u][v] = cur;
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(In,0, sizeof(In));
    memset(rls,0, sizeof(rls));
    memset(head,-1, sizeof(head));

    sign = 0;
}

void TopoDegree(int In[],int & sign){
    queue<int> rt;

    bool vis[MAXV];

    memset(vis,0, sizeof(vis));

    for (int i = 0; i < n; ++i) {
        if (!In[i]) rt.push(i);
    }

    anscur = 0;

    bool flag = true;
    while (!rt.empty()){
        int s = rt.front();
        rt.pop();

        if (vis[s]){
            sign = -1;
            return;
        }

        if (sign != 1)ans[anscur++] = s + 'A';

        vis[s] = true;

        if (!rt.empty()) flag = false;


        for (int i = head[s]; ~i ; i = G[i].next) {
            if (!(--In[G[i].v])) rt.push(G[i].v);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            sign = -1;
            return;
        }
    }

    sign = flag;
}


int main(){
    int tmp[MAXV];

    while (~scanf("%d%d",&n,&m) && (n||m) ) {
        init();
        int scrip = -1;

        for (int i = 0; i < m; ++i) {

            anscur = 0;

            scanf("%s", seq);
            if (sign) continue;
            //有环:-1 不可确定:0 确定:1
            int u = seq[2] - 'A';
            int v = seq[0] - 'A';
            if (rls[u][v]) continue;

            addedge(u, v);
            rls[u][v] = true;
            In[v]++;

            memcpy(tmp,In, sizeof(tmp));
            TopoDegree(tmp,sign);

            if (!(~sign)) printf("Inconsistency found after %d relations.\n",i+1);

            if (sign == 1 && !(~scrip)) {
                scrip = i+1;
                ans[anscur] = '\0';
            }

        }

        if (sign == 1) {
            printf("Sorted sequence determined after %d relations: ", scrip);
            int len = strlen(ans);
            for (int i = len - 1; i >=0  ; --i) {
                printf("%c",ans[i]);
            }
            printf(".\n", scrip, ans);
        } else if (sign == 0) {
            puts("Sorted sequence cannot be determined.");
        }
    }
}




//
//bool TopoSort(int u){
//    if (vis[u]) return true;
//    vis[u] = true;
//    //有环
//
//    for (int i = 0; i < n; ++i) {
//        if (!color[i] && rls[u][i]) {
//            if (TopoSort(i)) return true;
//        }
//    }
//
//    color[u] = true;
//    if (sign != 1) ans[anscur++] = u + 'A';
//    vis[u] = false;
//    return false;
//
//}
//
//int main(){
//    while (~scanf("%d%d",&n,&m) && (n||m) ){
//        init();
//        int scrip = -1;
//
//        for (int i = 0; i < m; ++i) {
//
//            anscur = 0;
//
//            scanf("%s",seq);
//            if (!(~sign)) continue;
//            //有环:-1 不可确定:0 确定:1
//            int u = seq[2] - 'A';
//            int v = seq[0] - 'A';
//            rls[u][v] = 1;
//            In[v]++;
//
//            int count = 0;
//            memset(color,0, sizeof(color));
//
//            for (int j = 0; j < n; ++j) {
//                if (!In[j]){
//                    count ++;
//                    if(TopoSort(j)) {
//                        sign = -1;
//                        break;
//                        //有环
//                    }
//                }
//
//            }
//
//            for (int j = 0; j < n; ++j) {
//                if (!color[j]) sign = -1;
//            }
//
//            if (!(~sign)){
//                sign = -1;
//                printf("Inconsistency found after %d relations.\n",i+1);
//                continue;
//            }
//
//            if (count == 1){
//
//                sign = 1;
//                if (!(~scrip)) {
//                    scrip = i+1;
//                    ans[anscur] = '\0';
//                }
//            }
//
//        }
//
//        if(sign == 1){
//            printf("Sorted sequence determined after %d relations: %s.\n",scrip,ans);
//        } else if(sign == 0){
//            puts("Sorted sequence cannot be determined.");
//        }
//    }
//
//}
