//
// Created by Henry on 16/8/27.
//
#include <cstdio>

#define NUM 30

bool tri[NUM][NUM];
int count[2],counter;

bool judge(int n){
    if (n==0) return count[0] == count[1];

    for (int i = 0; i < n; ++i) {
        tri[n-1][i] = tri[n][i] ^ tri[n][i+1];
        count[tri[n-1][i]]++;
    }

    return judge(n-1);
}

void dfs(int n,int pos){
    if (pos == n) {
        count[0] = count[1] = 0;
        if (judge(n)) counter++;
        return;
    }

    tri[n][pos] = 0;
    dfs(n,pos+1);
    tri[n][pos] = 1;
    dfs(n,pos+1);
}


char ans[][20] = {"1 0",
              "2 0",
              "3 4",
              "4 6",
              "5 0",
              "6 0",
              "7 12",
              "8 40",
              "9 0",
              "10 0",
              "11 171",
              "12 410",
              "13 0",
              "14 0",
              "15 1896",
              "16 5160",
              "17 0",
              "18 0",
              "19 32757",
              "20 59984",
              "21 0",
              "22 0",
              "23 431095",
              "24 822229"};

int main(){
    int n;
    while (scanf("%d",&n)!=EOF && n){
        printf("%s\n",ans[n-1]);
    }
//    for (int i = 1; i <= 24 ; ++i) {
//        counter = 0;
//        dfs(i,0);
//        printf("\"%d %d\",\n",i,counter);
//    }

}
