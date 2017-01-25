//
// Created by Henry on 16/9/7.
//

#include <iostream>
#include <vector>

#define TOALPHA(a) (a + 'A')
using namespace std;

const int MAXN = 100;

int offset[][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};


bool vis[MAXN][MAXN];
vector<int> ansx;
vector<int> ansy;

int n,m,cnt;
bool inside(int r,int c){
    return r<n && r>=0 && c<m && c>=0;
}

bool dfs(int r,int c){

    if(cnt == n*m ) return true;

    for (int i = 0; i < 8; ++i) {
        int dr = r+offset[i][0];
        int dc = c+offset[i][1];

        if(!vis[dr][dc] && inside(dr,dc)){
            vis[dr][dc] = true;
            cnt++;
            if(dfs(dr,dc)){
                ansx.push_back(dr);
                ansy.push_back(dc);
                vis[dr][dc] = false;
                return true;
            }
            cnt--;
            vis[dr][dc] = false;

        }
    }

    return false;
}


void prtans(int r,int c){
    printf("%c%d",TOALPHA(r),c+1);
    for (int i = ansx.size() -1; i >=0 ; --i){
        printf("%c%d",TOALPHA(ansx[i]),ansy[i] +1);

    }
}
int main(){
    int cases;
    cin>>cases;
    vis[0][0] = true;
    for (int i = 1; i <= cases ; ++i) {
        ansx.clear();
        ansy.clear();
        printf("Scenario #%d:\n",i);

        cin>>m>>n;
        cnt = 1;
        if (dfs(0,0)){

            prtans(0,0);
            puts("");
        } else{
            puts("impossible");
        }
        puts("");
    }
}