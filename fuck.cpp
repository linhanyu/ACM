//
// Created by Henry on 16/12/8.
//

#include <cstdio>

int draw(int r,int c,int pos,int color){ return r == 0 ? 1 : pos == c ? (puts(""),draw(r-1,c,0,c&1 ? color : !color)) : (printf("%d",color),draw(r,c,pos+1,!color)); }

int main(){
    draw(2,4,0,1);
}