//
// Created by Henry on 17/1/25.
//
#include <cstdio>

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

char str[MAXN][5];
int l[MAXN],r[MAXN];


int main(){
    int n;
    while (~scanf("%d",&n)){
        for (int i = 0; i < n; ++i) {
            scanf("%s",str[i]);
        }

        int cnt=INF;
        for (int i = 0; i < n; ++i) {
            if (str[i][0] != '?') cnt = 0;
            l[i] = cnt++;
        }

        for (int i = n-1; i >= 0; --i) {
            if (str[i][0] != '?') cnt = 0;
            r[i] = cnt++;
        }

        int q;
        scanf("%d",&q);
        while (q--){
            int pos;
            scanf("%d",&pos);
            pos--;
            if (l[pos] == r[pos]){
                if (l[pos] == 0){
                    printf("%s\n",str[pos]);
                } else{
                    printf("middle of %s and %s\n",str[pos - l[pos]],str[pos + r[pos]]);
                }
            } else{
                if (l[pos] < r[pos]){
                    for (int i = 0; i < l[pos]; ++i) {
                        printf("right of ");
                    }
                    printf("%s\n",str[pos - l[pos]]);
                } else{
                    for (int i = 0; i < r[pos]; ++i) {
                        printf("left of ");
                    }
                    printf("%s\n",str[pos + r[pos]]);
                }
            }
        }
    }
}
