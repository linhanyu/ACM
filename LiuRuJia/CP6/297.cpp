//
// Created by Henry on 16/9/4.
//
#include <cstdio>
#include <iostream>

#define HALF(a) (a>>1)

using namespace std;

const int len = 32;
const int MAXN = 1024+10;

char seq[MAXN];
int Graph[len][len],cnt;

void draw(char seq[],int & cur,int r,int c,int w){
    char ch = seq[cur++];
    if (ch == 'p'){
        draw(seq,cur,r,c ,HALF(w));
        draw(seq,cur,r + HALF(w),c ,HALF(w));
        draw(seq,cur,r,c + HALF(w) ,HALF(w));
        draw(seq,cur,r + HALF(w),c + HALF(w) ,HALF(w));
    } else if (ch == 'f'){
        for (int i = r; i < r+w; ++i) {
            for (int j = c; j < c+w; ++j) {
                if (Graph[i][j]) continue;
                Graph[i][j] = 1;
                cnt++;
            }
        }
    }

}

int main(){
    int cases;
    cin>>cases;
    while (cases--){
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                Graph[i][j] = 0;
            }
        }

        cnt = 0;

        for (int i = 0; i < 2; ++i) {
            cin>>seq;
            int p = 0;
            draw(seq,p,0,0,len);
        }

        printf("There are %d black pixels.\n",cnt);
    }
}