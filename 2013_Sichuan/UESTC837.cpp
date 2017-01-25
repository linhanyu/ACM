////
//// Created by Henry on 16/11/27.
////
#include <cstdio>

const int MAXN = 100000 + 10;

int A[MAXN];

int n,t,ans;
int main(){

    scanf("%d",&t);
    for (int cases = 1; cases <= t  ; ++cases) {
        ans = 1;
        printf("Case #%d: ",cases);

        scanf("%d",&n);

        for (int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
        }

//        if (A[1] - A[0] != 1 && A[2] - A[1] == 1){
//            puts("1");
//            continue;
//        }


        for (int i = 1; i < n ; ++i) {
            if (A[0] + i != A[i]){
                ans = i+1;
                break;
            }
        }
        printf("%d\n",ans);

    }


}


//#include <cstdio>
//
//const int MAXN = 100000 + 10;
//
//int A[3];
//
//int n,t,fuck;
//int main(){
//    scanf("%d",&t);
//    for (int cases = 1; cases <= t  ; ++cases) {
//        printf("Case #%d: ",cases);
//
//        scanf("%d",&n);
//
//        for (int i = 0; i < 3; ++i) {
//            scanf("%d",&A[i]);
//        }
//
//        int scrip;
//        for (int i = A[2] + 1; i < A[0] + n; ++i) {
//            int tmp;
//            scanf("%d",&tmp);
//            if (tmp != i){
//                scrip = i - A[0];
//            }
//        }
//
//
//        if (A[1] - A[0] != 1 && A[2] - A[1] == 1){
//            puts("1");
//            continue;
//        }
//
//        if (A[1] != A[0] + 1){
//            puts("2");
//            continue;
//        }
//
//        if (A[2] != A[1] + 1){
//            puts("3");
//            continue;
//        }
//
//
//
//        printf("%d\n",scrip);
//
//
//    }
//
//
//}
