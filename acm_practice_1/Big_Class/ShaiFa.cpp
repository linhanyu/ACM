//
// Created by Henry on 16/7/7.
//

#include <cstdio>

#define c 100001

bool su[c];
void init_su(){
    for (int i = 0; i < c; ++i) {
        su[i] = true;//将所有数设为素数
    }

    su[1] = false;//特别地,1不是素数

    for (int i = 2; i < c; ++i) {
        if (su[i]){ //若遍历中,发现某个数为素数
            for (int j = i * 2; j < c; j += i) {
                su[j] = false;//则将i的2,3,4倍数...的数都设为合数
            }
        }
    }

}

//int main(){
//    init_su();
//
//}