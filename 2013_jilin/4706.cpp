//
// Created by Henry on 17/1/29.
//

#include <cstdio>
#include <memory.h>

char mp[15][15];

char getC(){
    int static cur = 0;
    if (cur < 26){
        return 'a' + cur++;
    } else{
        cur = 1;
        return 'a';
    }
}


int main(){
    for (int size = 3; size <= 10; ++size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                mp[i][j] = ' ';
            }
        }

        for (int i = 0; i < size; ++i) {
            mp[i][size] = '\0';
        }

        for (int i = 0; i < size; ++i) {
            mp[i][0] = getC();
        }

        for (int i = 1; i < size - 1; ++i) {
            mp[size - i -1][i] = getC();
        }

        for (int i = 0; i < size; ++i) {
            mp[i][size - 1] = getC();
        }

        for (int i = 0; i < size; ++i) {
            puts(mp[i]);
        }
    }
}