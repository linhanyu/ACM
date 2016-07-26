//
// Created by Henry on 16/7/7.
//


#define IS_ODD(a) (a&1)

long long fast_pow(long long base,long long mi){
   long long ans =1; //幂为0时,ans为1
    while (mi){ //幂不为0时,继续计算
        if (IS_ODD(mi)){
            ans *= base;
            mi--;
        }

        base *= base;
        mi>>=1;//除2
    }

    return ans;
}

