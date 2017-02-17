//
// Created by Henry on 17/2/7.
//

#include <memory.h>
#include <algorithm>

using namespace std;

const int MAXE = 1000;
const int MAXV = 1000;
const int MAXN = 50 + 10;
const int INF = 0x3f3f3f3f;

struct Edge{
    int u,v,cost;
}E[MAXE];

int pre[MAXV],ID[MAXV],vis[MAXV];
int dp[MAXN][MAXN];
int In[MAXV],val[26];
int n,m,ecur,rep,del;
char s[MAXN][MAXN];

int dpt(int a,int b){
    int len1 = strlen(s[a]);
    int len2 = strlen(s[b]);

    for (int i = 0; i <= len1; ++i) {
        dp[0][i] = len1 * del;
    }

    for (int i = 1; i <= len2 ; ++i) {
        dp[i][0] = dp[i-1][0] + val[s[b][i-1] - 'a'];
        for (int j = 1; j <= len1 ; ++j) {
            if (s[a][j-1] == s[b][i - 1]){
                dp[i][j] = dp[i-1][j-1] - del;
            } else{
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]+val[s[b][i-1]-'a'])
            }
        }
    }

    return dp[len2][len1] + rep;
}

int Zhuliu(int rt,int nv,int ne){
    int ret = 0;

    for (;;) {
        fill(In,In + nv,INF);

        for (int i = 0; i < ne; ++i) {
            if (E[i].cost < In[E[i].v] && E[i].u != E[i].v){
                pre[E[i].v] = E[i].u;
                In[E[i].v ] = E[i].cost;
                //切自环,出最小入边
            }
        }

        for (int i = 0; i < nv; ++i) {
            if (i == rt) continue;
            if (In[i] >= INF) return -1;
        }

        int cntnode = 0;
        memset(ID,-1, sizeof(ID));
        memset(vis,-1, sizeof(vis));
        In[rt] = 0;

        for (int i = 0; i < nv; ++i) {
            //标记环
            ret += In[i];
            int v = i;
            while (vis[v] != i && ID[v] == -1 && v != rt){
                vis[v] = i;
                //把环中各节点都标记为有入边的那个点，如下图，把1,2,3,4,5,6都标记为1
                v  = pre[v];
            }

            if (v != rt && ID[v] == -1){
                for (int u = pre[v]; u != v ; u = pre[v]) {
                    ID[u] = cntnode;
                }
                ID[v] = cntnode++;
            }
        }

        if (cntnode == 0) break;
        for (int i = 0; i < nv; ++i) {
            if (~ID[i]) continue;
            ID[i] = cntnode++;
        }

        //缩点,重标记

        for (int i = 0; i < ne; ++i) {
            int v= E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if (E[i].u != E[i].v) E[i].cost -= In[v];
        }

        nv = cntnode;
        rt = ID[rt];
    }

    return ret;

}

void init(){
    ecur = 0;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);
        scanf("%d%d",&rep,&del);
        for (int i = 0; i < 26; ++i) {
            scanf("%d",&val[i]);
        }

        scanf("%d",&n);
        n++;
        for (int i = 2; i <= n; ++i) {
            scanf("%d",s[i]);
        }
    }
}