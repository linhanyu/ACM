//
// Created by Henry on 16/7/18.
//

#include <cstdio>

#define NUM_1 5843
#define NUM_2 4
#define INF 0x7FFFFFFFF

int factor[NUM_2] = {2,3,5,7};
long long humbles[NUM_1];

void init(){
    for (int i = 1; i <= 10; ++i) {
        humbles[i] = i;
    }


    for (int i = 11; i < NUM_1; ++i) {
        long long min = INF;
        int count= 0;
        for (int j = i-1; j > 1;) {
            if (count == NUM_2){
               break;
            }

            if (humbles[j]*factor[count] <= humbles[i-1]){
                count++;
                continue;
            }

            if ( min > humbles[j]*factor[count] ){
                min = humbles[j]*factor[count];
            }

            --j;
        }
        humbles[i] = min;
    }
}

//void init(){
//    humbles[1] = 1;
//
//    for (int i = 2; i < NUM_1; ++i) {
//        long long min = INF;
//        for (int j = 0; j < i; ++j) {
//            for (int k = 0; k < NUM_2; ++k) {
//                if ( humbles[j] > humbles[i-1]/factor[k] && humbles[j] < min/factor[k]){
//                    //找一个比前一个humble大的最小的数做min
//                    min = humbles[j]*factor[k];
//                }
//            }
//        }
//        humbles[i] = min;
//    }
//}

int main(){
    init();
    int n,fg;
    while (scanf("%d",&n)!=EOF && n){
        printf("The %d",n);

        if(n%10 == 1 && n%100 != 11)
        {
            printf("st");
        }
        else if(n%10 == 2 && n%100 != 12)
        {
            printf("nd");
        }
        else if(n%10 == 3 && n%100 != 13)
        {
            printf("rd");
        }
        else printf("th");
        printf(" humble number is %d.\n",humbles[n]);


    }

}
