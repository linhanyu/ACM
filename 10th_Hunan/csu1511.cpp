//
// Created by Henry on 17/1/22.
//

#include<cstdio>
#include <algorithm>

#define ABS(a) ((a)>0?(a):-(a))

using namespace std;


int r[3],c[3];
int main(){
    int cases = 0;
    while (~scanf("%d%d%d%d%d%d",&r[0],&c[0],&r[1],&c[1],&r[2],&c[2])){
        printf("Case %d: ",++cases);
        if (r[0] + c[0] == r[1]+c[1]){
            //同一副对角线

            if (r[0] > r[1]) {
                swap(r[0],r[1]);
                swap(c[0],c[1]);
            }
            int step = r[1] - r[0];
            if (r[2] + c[2] == r[0] + c[0] && r[2] > r[0] && r[2] < r[1]){
                step++;
            }
            printf("%d\n",step);
        }else if (r[0] - c[0] == r[1]-c[1]){
            //同一主对角线

            if (r[0] > r[1]) {
                swap(r[0],r[1]);
                swap(c[0],c[1]);
            }
            int step = r[1] - r[0];
            if (r[2] - c[2] == r[0] - c[0] && r[2] > r[0] && r[2] < r[1]){
                step++;
            }
            printf("%d\n",step);
        } else{
            int rs = ABS(r[1] - r[0]);
            int cs = ABS(c[1] - c[0]);
            int step = max(rs,cs);

            printf("%d\n",step);
        }
    }

}