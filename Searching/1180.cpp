//
// Created by Henry on 16/9/19.
//

#include <cstdio>
#include <cstring>
#include <queue>

#define INF 0x7F

using namespace std;

int m,n,endi,endj;

const int MAXN = 20;
const int offset[][2] = {{-1,0},{1,0},{0,1},{0,-1}};

char Graph[MAXN + 10][MAXN + 10];


int dis[MAXN+10][MAXN+10];

struct node{
    int i,j,step;
    /* friend bool operator <(node a,node b){
        return a.step>b.step;
    } */
    bool operator <(const node &a)const{
        return step>a.step;//步数小的先出队列
    }

    bool operator ==(const node &a)const{
        return step== a.step && i==a.i && j==a.j;//步数小的先出队列
    }
};

void init(){
    memset(dis,INF, sizeof(dis));
}

bool inbound(int i){
    return i>=0 && i<n;
}

bool inbound(int i,int j){
    return i>=0 && i<m && j>=0 && j<n;
}

int bfs(int begini,int beginj){

    priority_queue<node > Q;
    node begin;

    begin.i = begini;
    begin.j = beginj;
    begin.step = 0;
    dis[begini][beginj] = 1;
    Q.push(begin);

    while(!Q.empty()){
        node source = Q.top();
        while (!Q.empty() &&  Q.top() == source)Q.pop();

        if(Graph[source.i][source.j] == 'T')
            return source.step;

        for (int i = 0; i < 4; ++i) {
            int di = source.i + offset[i][0];
            int dj = source.j + offset[i][1];
            int ddis  = source.step + 1;
            if (inbound(di,dj) && Graph[di][dj] != '*' && ddis < dis[di][dj]){

                if (Graph[di][dj] == '-'){
                    if ((di == source.i && !(ddis & 1)) || ((dj == source.j) && (ddis & 1))){
                        //i不变j变(竖着走),且
                        ddis++;
                    }

                    di += offset[i][0];
                    dj += offset[i][1];

                }else if (Graph[di][dj] == '|'){
                    if ((dj == source.j && !(ddis & 1)) || ((di == source.i) && (ddis & 1))){
                        //i不变j变(竖着走),且
                        ddis++;
                    }

                    di += offset[i][0];
                    dj += offset[i][1];
                }

                if (inbound(di,dj) && Graph[di][dj] != '*' && ddis < dis[di][dj]){

                    dis[di][dj] = ddis;
                    node n;
                    n.i = di;
                    n.j = dj;
                    n.step = ddis;
                    Q.push(n);
                }

            }
        }

    }

    return 0;



}

int main(){
    int begini,beginj;
    while(scanf("%d %d",&m,&n)!=EOF){
        init();

        for (int i = 0; i < m; ++i) {
            scanf("%s",Graph[i]);

            int tmp;
            tmp = strchr(Graph[i],'S') - Graph[i];

            if(inbound(tmp)){
                begini = i;
                beginj = tmp;

            }

        }

        printf("%d\n",bfs(begini,beginj));


    }

}