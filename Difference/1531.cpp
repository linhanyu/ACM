//
// Created by Henry on 16/9/2.
//
#include <algorithm>
#include <deque>
#include <memory>
#include <cstdio>

#define NUM 120
#define INF 32764
using namespace std;


struct Node{
    int next;
    int target;
    int weight;
} rls[NUM*4];

int cur;
int dis[NUM];
int head[NUM];

void addNode(int source,int target,int weight){
    rls[cur].weight = weight;
    rls[cur].target = target;
    rls[cur].next = head[source];
    head[source] = cur++;
}

bool spfa(int begin,int NodeNum){
    static bool inqueue[NUM];
    static int times[NUM];

    memset(inqueue,0, sizeof(inqueue));
    memset(times,0, sizeof(times));
    memset(dis,1, sizeof(dis));

    deque<int > Q;
    Q.push_front(begin);
    inqueue[begin]  = true;
    times[begin] = 1;
    dis[begin] = 0;

    while (!Q.empty()){
        int pre = Q.front();
        Q.pop_front();
        inqueue[pre] = false;


        for (int i = head[pre]; i != -1 ; i = rls[i].next) {

            const int & target = rls[i].target;
            const int & weight = rls[i].weight;

            if (dis[pre] + weight < dis[target]){

                dis[target] = dis[pre] + weight;
                if (!inqueue[target]){
                    if (++times[target] >= NodeNum) return true;

                    if (Q.empty() || dis[target] < dis[Q.front()]){
                        Q.push_front(target);
                    } else{
                        Q.push_back(target);
                    }
                    inqueue[target] = true;

                }
            }
        }
    }

    return false;

}

int main(){
    int n,m,si,ni,k,lower,upper;
    char op[10];
    while (scanf("%d",&n)!=EOF && n){
        scanf("%d",&m);
        cur = 0;
        memset(head,-1, sizeof(head));

        lower = NUM;
        upper = -1;

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %s %d",&si,&ni,op,&k);
            //f(si+ni+1) - f(si) ~ k
            if (op[0] == 'l'){
                //<
                addNode(si ,si + ni + 1,k-1);
            } else{
                //>
                addNode(si + ni + 1, si ,-k-1);
            }

        }

        for (int i = 1; i <= n+1; ++i) {
            addNode(0,i,0);
        }


        if (spfa(0,n+2)){
            puts("successful conspiracy");
        } else{
            puts("lamentable kingdom");
        }

    }
}