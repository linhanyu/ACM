//
// Created by Henry on 16/9/3.
//

#include <cstdio>
#include <memory>

#define NUM 20
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)

using namespace std;




int main(){
    int cases,D,I,cur;
    scanf("%d",&cases);

    while(scanf("%d %d ",&D,&I) == 2){
//        for (int i = 1; i < upper; ++i) {
//            Buffer[i] = false;
//        }
        cur = 1;
        for (int i = 0; i < D; ++i) {
            if (I & 1){
                cur = LC(cur);
                I = (I+1)>>1;
            } else{
                cur = RC(cur);
                I >>= 1;
            }
        }

        printf("%d\n",cur>>1);

    }

}
