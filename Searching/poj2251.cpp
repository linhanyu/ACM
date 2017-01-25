//
// Created by Henry on 16/10/20.
//

#include <cstdio>
#include <queue>

using namespace std;

struct ord{
    int i,j,k;
    ord(){}
    ord(int i,int j,int k):i(i),j(j),k(k){}
};

const int dir = 6;
const int MAXN = 32;
const int offset[dir][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int l,r,c;
int bi,bj,bk,ei,ej,ek;

int dis[MAXN][MAXN][MAXN];

char G[MAXN][MAXN][MAXN];

bool inBound(int i,int j,int k){
    return 0<=i && 0<=j && 0<=k && i<l && j<r && k<c;
}

int BFS(int begini,int beginj,int begink){
    memset(dis,-1, sizeof(dis));

    queue<ord> Q;

    Q.push(ord(begini,beginj,begink));
    dis[begini][beginj][begink] = 0;

    while (!Q.empty()){
        ord s = Q.front();
        Q.pop();

        for (int i = 0; i < dir; ++i) {
            int di = s.i + offset[i][0];
            int dj = s.j + offset[i][1];
            int dk = s.k + offset[i][2];

            if (inBound(di,dj,dk) && G[di][dj][dk] != '#' && !(~dis[di][dj][dk])){

                dis[di][dj][dk] = dis[s.i][s.j][s.k] + 1;

                if (di == ei && dj == ej && dk == ek) break;

                Q.push(ord(di,dj,dk));
            }

        }

    }

    return dis[ei][ej][ek];
}


void solve(){
    if (~BFS(bi,bj,bk)){
        printf("Escaped in %d minute(s).\n",dis[ei][ej][ek]);
    } else{
        puts("Trapped!");
    }
}

int main(){
    while (~scanf("%d %d %d",&l,&r,&c) && l ){
        getchar();

//        char G[MAXN][MAXN][MAXN];

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    scanf("%c",&G[i][j][k]);

                    if (G[i][j][k] == 'S'){
                        bi = i;
                        bj = j;
                        bk = k;
                    }else if (G[i][j][k] == 'E'){
                        ei = i;
                        ej = j;
                        ek = k;
                    }
                }
                getchar();
            }
            getchar();
        }

        solve();
    }
}