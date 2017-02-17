//
// Created by Henry on 17/2/6.
//

#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

const int f[]={1,1,2,6,24,120,720,5040,40320};
const int step[][3]={{1,2,3},{3,2,1},{4,5,6},{6,5,4},{7,8,9},{9,8,7},{7,4,1},{1,4,7},{2,5,8},{8,5,2},{3,6,9},{9,6,3}};
const int INF = 0x3f3f3f3f;


struct node
{
    int a[10];
}Q,R;

int dist[400005],use[10],to[10],v[10],num,ret;

int Cantor(node & a){
    int ret = 0;
    for (int i = 1; i <= 9; ++i) {
        int seg = 0;
        for (int j = i+1; j <= 9 ; ++j) if (a.a[j] < a.a[i]) seg++;
        ret += f[9 - i] * seg;

    }
    return ret;
}

node move(node st,int x,int y,int z){
    int tmp = st.a[x];
    st.a[x] = st.a[y];
    st.a[y] = st.a[z];
    st.a[z] = tmp;

    return st;
}

void bfs(){
    memset(dist,-1, sizeof(dist));

    node now;
    for (int i = 1; i <= 9 ; ++i) now.a[i] = i;
    dist[Cantor(now)] = 0;
    queue<node> Q;
    Q.push(now);

    while (!Q.empty()){
        now = Q.front();
        Q.pop();

        int s = Cantor(now);
        for (int i = 0; i < 12; ++i) {
            node tmp = move(now,step[i][0],step[i][1],step[i][2]);
            int v = Cantor(tmp);
            if (~dist[v]) continue;

            dist[v] = dist[s] + 1;
            Q.push(tmp);
        }
    }

}

void init(){
    memset(use,0, sizeof(use));
    memset(to,0,sizeof(to));
    num = 9;
    ret = INF;
}

int get()
{
    char s[3];
    scanf("%s",s);
    if(s[0]=='*') return 0;

    num--;
    return s[0]-'0';
}

void dfs(int st)
{
    int i,j,k=0;
    if(st>num)
    {
        R=Q;
        for(i=1;i<=9;i++) if(R.a[i]==0) R.a[i]=v[++k];
        j=Cantor(R); if(dist[j]!=-1) ret=min(ret,dist[j]);
        return ;
    }
    for(i=1;i<=9;i++)
    {
        if(use[i]==0)
        {
            use[i]=1; v[st]=i; dfs(st+1); use[i]=0;
        }
    }
}

int main(){
    bfs();
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);

        init();
        for(int i=1; i<=9; i++) {
            int tmp;
            scanf("%d",&tmp);
            to[tmp]=i;
        }
        for(int i=1; i<=9; i++) Q.a[i]=to[get()],use[Q.a[i]]=1;
        dfs(1);

        if(ret>= INF) puts("No Solution!");
        else printf("%d\n",ret);
    }
}