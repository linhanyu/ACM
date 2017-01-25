//
// Created by Henry on 16/8/14.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
#include <map>
#include <vector>

#define MID(a,b) ((a+b)>>1)
#define NUM 301
#define MOD 10001
#define INF 0x7FFFFFF
#define PRIMELEN 303
using namespace std;

int seq[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999};

int binarySearch(int left,int right,int key){
    int mid;
    while(left<=right){
        mid = MID(left,right);

        if (key < seq[mid]){
            right = mid - 1;
        } else if (key > seq[mid]){
            left = mid+1;
        } else{
            return right;
        }
    }

    return -1;
}

int counter;
void mergeMap(map<int,int > & newMap,map<int,int> & map1,map<int,int> & map2){

    for (auto i = map1.begin();i!=map1.end();i++){
        newMap[(*i).first] += (*i).second;
    }

    for (auto i = map2.begin();i!=map2.end();i++){
        newMap[(*i).first] += (*i).second;
    }
}


bool check(map<int,int> & Map){
    for (auto i = Map.begin();i!=Map.end();i++){
        if ((*i).second & 1){
            return false;
        }
    }
    return true;
}

void suYinZi(int n,map<int,int> & Map) {
    while((n & 1) == 0){
        n >>= 1;
        Map[2]++;
    }
    for (int i = 3; i <= n; i+=2) {
        while (n % i == 0) {
            n /= i;
            Map[i]++;
        }
    }
}

void print_subset(int n,bool* b,int cur){
    //当cur加到n的时候输出该串节点(解答树)的值
    if(cur==n){
        for (int i=0;i<n;i++){
            if(b[i])
                cout<<i<<' ';
        }
        cout<<endl;
        return ;
    }
    b[cur]=true;//该节点设为选中状态
    print_subset(n,b,cur+1);//cur+1递归该状态时的下一层节点,循环该操作
    b[cur]=false;//该节点设为不选中状态
    print_subset(n,b,cur+1);//cur+1递归该状态时的下一层节点,循环该操作
}

int main(){

    int t,n,tmp;
    map<int,int> A[NUM];
    map<int,int> dp[NUM][NUM];
    map<int,int> setinal;
    cin>>t;

    for (int cases = 1; cases <= t ; ++cases) {
        printf("Case #%d:\n",cases);
        cin>>n;
        counter = 0;

        for (int i = 1; i <= n; ++i) {
            cin>>tmp;
            A[i].clear();
            for (int j = 1; j <= n; ++j) {
                dp[i][j].clear();
            }

            suYinZi(tmp,A[i]);


            mergeMap(dp[i][i],A[i],setinal);
            if (check(dp[i][i])) counter++;
//            dp[i][i] = A[i];

        }



        for (int i = 2; i <= n ; ++i) {
            for (int j = i; j <= n ; ++j) {
                //j-i+1 ~ j
                mergeMap(dp[j-i+1][j],dp[j-i+1][j-1],A[j]);
                if (check(dp[j-i+1][j])) counter++;

            }
        }

        printf("%d\n",counter);

    }

}
//int weight[NUM];
//int rls[NUM][NUM];
//int dp[NUM];
//int n;
//int dfs(int root,int pre){
//
//    if (dp[root]){
//        return dp[root];
//    }
//
//    int Max = weight[root];
//    for (int i = 1; i <= n ; ++i) {
//        if (i!=pre && root != i && rls[root][i]!=INF ) {
//            int tmp = dfs(i,root) - rls[root][i];
//            if (tmp >0){
//                Max += tmp;
//            }
//        }
//    }
//
//    return dp[root] = Max;
//}
//
//int main(){
//    int t,count = 1;
//
//    cin>>t;
//    while(t--){
//        printf("Case #%d: ",count++);
//        cin>>n;
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = i; j <= n; ++j) {
//                rls[i][j] = rls[j][i] = INF;
//            }
//        }
//
//        for (int i = 1; i <= n ; ++i) {
//            cin>>weight[i];
//            rls[i][i] = 0;
//        }
//
//        int u,v,c;
//        for (int i = 1; i < n ; ++i) {
//            cin>>u>>v>>c;
//            rls[u][v] = rls[v][u] = c;
//        }
//
//
//
//
//
//        for (int i = 1; i <= n ; ++i) {
//            memset(dp,0, sizeof(dp));
//            printf("%d\n",dfs(i,0));
//        }
//    }
//
//}
//int main()
//{
//    int n,t;
//    int count = 1;
//    int a[NUM];
//
//    scanf("%d",&t);
//    while(t--)
//    {
//        printf("Case #%d: ",count++);
//
//        scanf("%d",&n);
//        int Max=0;
//        int sum=0;
//
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//            Max = max(Max,a[i]) ;
//            sum+=a[i];
//        }
//
//        int ans=sum-Max;
//
//        if(sum>(ans<<2)+2)
//            printf("%d\n",(ans<<1)+1);
//        else
//            printf("%d\n",(sum>>1));
//    }
//}

//int main() {
//    int n,len;
//    int count=1;
//    map<char,int> Map;
//    char seq[NUM];
//
//
//    scanf("%d",&n);
//    while(n--){

//
//        Map.clear();
//        scanf("%s",seq);
//
//
//        len = (int)strlen(seq);
//
//        for(int i=0;i<len;i++){
//            Map[seq[i]] ++;
//        }
//        int sum =0;
//
//        for(char i='a';i<='z';i++){
//            if(Map[i])
//                sum++;
//        }
//
//        printf("%d\n",sum);
//    }
//}

//int main()
//{
//    int ans,count=1;
//    char seq[NUM];
//
//    while(scanf("%s",seq)!=EOF)
//    {
//
//        printf("Case #%d: ",count++);
//        int len = (int)strlen(seq);
//        for (int i = 0; i < len; ++i) {
//            seq[i] -= '0';
//        }
//        ans = 0;
//
//        for (int i = 0; i < len; ++i) {
//            ans = (ans*10 + (int)seq[i]) % MOD;
//        }
//
//        if (ans % MOD){
//            printf("NO\n");
//        } else{
//            printf("YES\n");
//
//        }
//
//    }
//}

//int binarySearch(int left,int right,char seq[],char key){
//    int mid;
//    while(left<=right){
//        mid = MID(left,right);
//
//        if (key < seq[mid]){
//            right = mid - 1;
//        } else if (key > seq[mid]){
//            left = mid+1;
//        } else{
//            break;
//        }
//    }
//
//    return left;
//}



//int main(){
//    int n;
//    int t;
//    int count =1;
//    char stack[NUM];
//    char seq[NUM];
//    int len,cur;
//    cin>>t;
//    while (t--){
//        printf("Case #%d: ",count++);
//
//        scanf("%s\n",seq);
//        len = (int)strlen(seq);
//        cur = 0;
//
//        stack[cur] = seq[0];
//
//        for (int i = 1; i < len; ++i) {
//            if (stack[cur] < seq[i]){
//                stack[++cur] = seq[i];
//            } else{
//                stack[binarySearch(0,cur,stack,seq[i])] = seq[i];
//            }
//        }
//
//        printf("%d\n",cur+1);
//
//
//    }
//}

//int main(){
//    int n;
//    int count = 1;
//    while (cin>>n){
//
//        printf("Case #%d: ",count++);
//
//        if(n % 10001 == 0){
//            printf("YES\n");
//        } else{
//            printf("NO\n");
//        }
//
//    }
//}