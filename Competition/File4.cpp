#include <cstdio>
#include <queue>
#include <functional>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1000000000;
int dp[4][MAXN];
int L[4],R[4];
long long sum,count;
void solve(){
    for (int i = 0; i < 4; ++i) {
        for (int j = L[i]; j <= R[i] ; ++j) {
            dp[i][j] = dp[i-1][j] ^ j;
            if (dp[i][j] == 0){
                count++;


            }
        }
    }

}
int main(){

}


//const int MAXN = 110;
//const int OFFSET = 300;
//
//int BUFFER[MAXN + OFFSET];
//
//int Find(int root){
//    if (BUFFER[root] < 0){
//        return root;
//    } else{
//        return BUFFER[root] = Find(BUFFER[root]);
//    }
//}
//
//bool flag;
//void Merge(int rt1,int rt2){
//    int r1 = Find(rt1);
//    int r2 = Find(rt2);
//
//    if (r1 == r2){
//        return;
//    }
//
//    BUFFER[r2] = r1;
//
//
//}
//
//void init(){
//    for (int i = 0; i < MAXN+OFFSET; ++i) {
//        BUFFER[i] = -1;
//    }
//    flag = true;
//}
//
//int main(){
//    int cur,t,n;
//    map<string,int> hash;
//    string tmp1,tmp2;
//
//    scanf("%d",&t);
//    for (int cases = 1; cases <= t; ++cases) {
//
//        init();
//        cur = 1;
//        hash.clear();
//        printf("Case #%d: ",cases);
//
//        scanf("%d",&n);
//        for (int i = 0; i < n; ++i) {
//            cin>>tmp1>>tmp2;
//
//            if (!flag) continue;
//
//            if (hash[tmp1] == 0){
//                hash[tmp1]= cur++;
//            }
//
//            if (hash[tmp2] == 0){
//                hash[tmp2] = cur++ ;
//            }
//
//            if(Find(hash[tmp1]) == Find(hash[tmp2]) || Find(hash[tmp1]+OFFSET) == Find(hash[tmp2]+OFFSET)) {
//                flag = false;
//            } else{
//                Merge(hash[tmp1]+OFFSET ,hash[tmp2]);
//                Merge(hash[tmp1] ,hash[tmp2] + OFFSET);
//            }
//
//
//        }
//
//        if (flag){
//            puts("Yes");
//        } else{
//            puts("No");
//        }
//    }
//}

//
//#define L(a) (a<<1)
//#define R(a) (a<<1|1)
//#define MID(a,b) ((a+b)>>1)
//
//const int MAXN = 1000000001;
//const int MOD = 1000000007;
//
//using namespace std;
//
//struct duan{
//    int L;
//    int R;
//}ord[4];
//
//int stack[20];
//
//
//int main(){
//    long long tmpL,tmpR,L,R;
//    bool flag = false;
//    while (true){
//
//        for (int i = 0; i < 4; ++i) {
//            L = 0,R = MAXN;
//            if (scanf("%lld %lld",&ord[i].L,&ord[i].R) == EOF) {
//                flag = true;
//                break;
//            }
//            L = max(tmpL,L);
//            R = min(tmpR,R);
//        }
//
//        if(flag) break;
//
//        if (L>R){
//            puts("0 0");
//        } else{
//            printf("%lld %lld\n",(R-L+1) % MOD,(R/2) * ((R-L)/2)% MOD);
//        }
//
//
//
//
//    }
//}
//

//#define ABS(a) ((a) > 0? (a):(-(a)))
//#define P2(a) ((a)*(a))
//const int MAXN = 10001;
//const int offset[][2] = {{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
//
//struct node{
//    int r;
//    int c;
//    int num;
//
//    node(){};
//    node(int r,int c):r(r),c(c){}
//
//}Buffer[MAXN][MAXN];
//
//int n,m;
//bool OutBound(int row,int col){
//    return col < 1 || row < 1 || row >n || col>n;
//}
//
//node find(int r,int c){
//    if (Buffer[r][c].r < 0){
//        return node(r,c);
//    } else{
//        node nd = find(Buffer[r][c].r,Buffer[r][c].c);
//        Buffer[r][c].r = nd.r;
//        Buffer[r][c].c = nd.c;
//        return nd;
//    }
//}
//
//void merge(int r1,int c1,int r2,int c2){
//    node rt1 = find(r1,c1);
//    node rt2 = find(r2,c2);
//
//    if (rt1.r == rt2.r && rt1.c == rt2.c) return;
//
//    Buffer[rt2.r][rt2.c].r = rt1.r;
//    Buffer[rt2.r][rt2.c].c = rt1.c;
//    Buffer[rt1.r][rt1.c].num += Buffer[rt2.r][rt2.c].num;
//
//}
//
//void init(){
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= m; ++j) {
//            Buffer[i][j].num = 1;
//            Buffer[i][j].r = Buffer[i][j].c = -1;
//        }
//    }
//}
//
//int cenr,cenc,cons1,cons2;
//int op;
//bool inCircle(int r,int c){
//    return P2(r-cenr) + P2(c-cenc) <= P2(cons1);
//}
//
//bool inDiamond(int r,int c){
//    return ABS(r-cenr) + ABS(c-cenc) <= cons1;
//}
//
//bool inRectangle(int r,int c){
//    return cenc <= r && cenr <= c && c <= cenc+cons2-1 && r <= cenr+cons1 -1;
//}
//
//bool inTriangle(int r,int c){
//    return ABS(r-cenr) + ABS(c-cenc) <= cons1;
//}
//void dfs(int r,int c){
//
//}
//
//int main(){
//    char tmp[30];
//}




