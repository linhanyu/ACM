//
// Created by Henry on 17/2/8.
//

#include <cstdio>
#include <cstring>
const int MAXN = 100 + 10;

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char str[2][10 * MAXN];

void encode(int ans){

}


int main(){
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d: ",cases);

        int k,ans = 0;
        scanf("%d%s",&k,str[0]);
        while (k--){
            ans = !ans;
            encode(ans);
        }

        printf("%s\n",str[ans]);
    }
}