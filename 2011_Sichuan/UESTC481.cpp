//
// Created by Henry on 17/2/5.
//

#include <cstdio>
#include <cmath>


int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
        printf("Case #%d: ",cases);

        double fuck;
        scanf("%lf",&fuck);

        if (fuck >= 1){
            puts("Too Bright");
        } else if (fuck >= 0.4){
            puts("1");
        } else if (fuck >= 0.16){
            puts("2");
        } else if (fuck >= 0.063){
            puts("3");
        } else if (fuck >= 0.025){
            puts("4");
        } else if (fuck >= 0.01){
            puts("5");
        } else if (fuck >= 0.004){
            puts("6");
        } else{
            puts("Invisible");
        }
    }
}
