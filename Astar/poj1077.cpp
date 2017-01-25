//
// Created by Henry on 16/10/26.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;

const int step[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
const char op[] = {'u','l','r','d'};


int G[9];

int depth;
int mi;
char ans[1005];
bool flg;

int h(){
    int cost=0;
    for (int i = 0; i < 9; ++i) {
        if (G[i]!=8){
            cost += abs(i/3 - G[i]/3) + abs(i%3 - G[i]%3);
        }
    }

    return cost;
}

bool Outbound(int x,int y){
    return x<0 || x>2 || y<0 || y>2;
}

void DFS(int x,int d,int pre){
    int t = h();

    if (mi > t)mi = t;

    if (d + t > depth || flg) return;

    if (!t){
        flg = true;
        ans[d] = '\0';
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int dr = x/3 + step[i][1];
        int dc = x%3 + step[i][0];
        int dx = dr*3 + dc;

        if (Outbound(dr,dc) || dx == pre) continue;


        swap(G[dx],G[x]);
        ans[d] = op[i];

        DFS(dx,d+1,x);
        if (flg) return;

        swap(G[dx],G[x]);
    }
}


void idaStar(int x){
    int i,j;
    depth = h();
    flg = false;
    while (!flg){
        mi = INF;
        DFS(x,0,-1);
        depth += mi;
    }
}

int main(){
    while (~scanf("%s",ans)){

        int x;

        if (ans[0] > '0' && ans[0]<='9'){
            G[0] += ans[0] - '0' - 1;
        } else if (ans[0] == 'x'){
            x = 0;
            G[0] = 8;
        }


        for (int i = 1; i < 9; ++i) {
            scanf("%s",ans);
            if (ans[0] > '0' && ans[0]<='9'){
                G[i] += ans[0] - '0' - 1;
            } else if (ans[0] == 'x'){
                x = i;
                G[i] = 8;
            }
        }

        idaStar(x);
        printf("%s\n",ans);
    }
}