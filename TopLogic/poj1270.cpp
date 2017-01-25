//
// Created by Henry on 16/12/2.
//


#include <cstdio>
#include <memory.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 600;
const int MAXT = 10000;

struct edge{
    int v,next;
}G[MAXT];

int head[MAXN];
int v[MAXN];
int In[MAXN];

char tmp[MAXT];
char ans[MAXN];

bool vis[MAXN];

int cur,len;

void addedge(int u,int v){
    G[cur].v = v;
    G[cur].next = head[u];
    head[u] = cur++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(In,0, sizeof(In));
    memset(vis,0, sizeof(vis));
    memset(ans,0, sizeof(ans));

    len  = cur = 0;

}

void dfs(int d){
    if (len == d){
        printf("%s\n",ans);
        return;
    }

    for (int a = 0; a < 26; ++a) {
        int i = *lower_bound(v,v+len-1,a);

        if (i != a) continue;
        if (!In[i] && !vis[i]){
            for (int e = head[i]; ~e ; e = G[e].next) {
                In[G[e].v]--;
            }

            In[i]--;
            ans[d] = i + 'a';
            vis[i] = true;
            dfs(d+1);
            vis[i] = false;
            In[i]++;
            for (int e = head[i]; ~e ; e = G[e].next) {
                In[G[e].v]++;
            }
        }
    }
}

int main(){
    while (scanf("%[^\n]",tmp) != EOF){
        getchar();

        init();

        for (int i = 0; i < strlen(tmp); ++i) {
            if (tmp[i] != ' ') v[len++] = tmp[i] - 'a';
        }

        sort(v,v+len);

        scanf("%[^\n]",tmp);
        getchar();

        int front,behind;
//        for (int i = 0; i < strlen(tmp); ++i) {
//            if (tmp[i] != ' '){
//                if (~front){
//                    int u = lower_bound(v,v+len,tmp[front] - 'a') - v;
//                    int v_ = lower_bound(v,v+len,tmp[i] - 'a') - v;
//
//                    addedge(u,v_);
//                    In[v_]++;
//                    front = -1;
//                } else{
//                    front = i;
//                }
//            }
//        }

        for(int i=0;i<strlen(tmp);++i){
            while(tmp[i] == ' ') ++i;
            front = tmp[i++] - 'a';
            while(tmp[i] == ' ') ++i;
            behind = tmp[i] - 'a';


            addedge(front,behind);
            In[behind]++;
        }

        dfs(0);
        puts("");
    }
}