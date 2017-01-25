//
// Created by Henry on 16/9/12.
//

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define diffodd(a,b) (((a)^(b))&1)

using namespace std;

const int MAXN= 11;

struct status{
    int i;
    int j;
    int time;
    status(int i,int j,int time):i(i),j(j),time(time){}
};


int offset[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,maxT;
char graph[MAXN][MAXN];
int startr,startc,endr,endc;
int flag;
bool visiting[MAXN][MAXN];

bool judge(int r,int c){
    return r<n && r>=0 && c<m && c>=0 && graph[r][c]!='X';
}


//
//bool BFS(status begin){
//    static bool unvisited[MAXN][MAXN];
//
//    memset(unvisited,1, sizeof(unvisited));
//    queue<status> Q;
//    Q.push(begin);
//    unvisited[begin.i][begin.j] = false;
//
//    while(!Q.empty()){
//        status source = Q.front();
//
//        if (source.time > maxT){
//            return false;
//        }
//
//        if (graph[source.i][source.j] == 'D'){
//            return true;
//        }
//
//        Q.pop();
//
//        for (int i = 0; i < 4; ++i) {
//            int dx = source.i + offset[i][0];
//            int dy = source.j + offset[i][1];
//
//            if (judge(dx,dy) && unvisited[dx][dy]){
//                unvisited[dx][dy] = false;
//                Q.push(status(dx,dy,source.time+1));
//            }
//        }
//    }
//    return false;
//}

int cut(const status & source){
    //行+列奇偶性相同,则移动偶数步可达
    //行+列奇偶不同,则奇数步可达
    //
    if(diffodd(source.i+source.j,flag)){
        //奇偶性不同
        return !((maxT-source.time)&1);
    } else{
        return (maxT-source.time)&1;
    }

}

bool DFS(status u){

    if (u.time > maxT || cut(u)){
        return false;
    } else if(maxT == u.time && graph[u.i][u.j] == 'D'){
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        int dx = u.i + offset[i][0];
        int dy = u.j + offset[i][1];
        if (judge(dx,dy) && !visiting[dx][dy] ){
            visiting[dx][dy] = true;
            if (DFS(status(dx,dy,u.time+1)))
                return true;
            visiting[dx][dy] = false;
        }
    }
    return false;
}

int main(){
    while(scanf("%d %d %d",&n,&m,&maxT)!=EOF&& (n||m||maxT)){

        for (int i = 0; i < n; ++i) {
            scanf("%s",graph[i]);
            int tmp1 = strchr(graph[i],'S') - graph[i];
            int tmp2 = strchr(graph[i],'D') - graph[i];

            if (tmp1 < m && tmp1>=0){
                startr = i;
                startc = tmp1;
            }

            if (tmp2 < m && tmp2>=0){
                endr = i;
                endc = tmp2;
            }
        }

        flag = endc|endr;
        memset(visiting,0, sizeof(visiting));
        visiting[startr][startc] = true;
        if (DFS(status(startr,startc,0))){
            puts("YES");
        } else{
            puts("NO");
        }
    }
}