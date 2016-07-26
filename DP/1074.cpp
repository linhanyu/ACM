//
// Created by Henry on 16/7/20.
//

#include <cstdio>
#include <memory>
#define BIT 16
#define MAXN (1<<BIT)
#define NUM_2 101
struct Node{
    int cost;
    int pre;
    int reduced;
}dp[MAXN];
bool visited[MAXN];

struct Course{
    int deadline;
    int cost;
    char name[NUM_2];
}course[BIT];


void output(int statu){
    int cur_job = statu ^ dp[statu].pre;
    //取出最后一次完成的作业
    int curid = 0;
    cur_job >>= 1;
    while(cur_job){
        curid ++;
        cur_job>>=1;
    }
    //第几位
    if(dp[statu].pre != 0 ){
        //尾递归,从第一个完成的开始打印
        output(dp[statu].pre);
    }

    printf("%s\n",course[curid].name);

}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int upper = 1<<n;
        //比方说n=2,1<<2就是100
        int day_upper = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s %d %d",course[i].name,&course[i].deadline,&course[i].cost);
            day_upper += course[i].cost;
        }

        memset(visited,0, sizeof(visited));
        dp[0].cost = 0;
        dp[0].pre = -1;
        dp[0].reduced = 0;
        visited[0] = true;
        int work;
        int t_upper = upper-1;
        //upper-1,如n=2,(1<<2) -1 = 011,刚好对应前两个数之状态;
        for(int i=0;i<t_upper;i++){
            //遍历所有状态
            for (int work = 0; work < n; ++work) {
                int cur = 1<<work;
                //用"1"作指针,扫过1~n-1位
                if ((cur & i)==0){
                    //作业没做过
                    int cur_tmp = cur | i;
                    //那就做呗
                    int day =  dp[i].cost + course[work].cost;
                    dp[cur_tmp].cost = day;
                    int reduced = day - course[work].deadline;

                    if (reduced < 0) reduced = 0;
                    //如果做完没到dealine,那就不记分
                    reduced += dp[i].reduced;
                    //加上前一种状态得分
                    if (visited[cur_tmp]){
                        if (reduced < dp[cur_tmp].reduced){
                            dp[cur_tmp].reduced = reduced;
                            dp[cur_tmp].pre = i;
                        }
                    }
                    else{
                        visited[cur_tmp] = true;
                        dp[cur_tmp].reduced = reduced;
                        dp[cur_tmp].pre = i;
                    }

                }
            }
        }
        printf("%d\n",dp[t_upper].reduced);
        output(t_upper);

    }
}

//#include <cstdio>
//
//#define NUM_1 102
//#define NUM_2 16
//#define NUM_3 10000
//struct Course{
//    int deadline;
//    int cost;
//    char name[NUM_1];
//}Course[NUM_2];
//ddddfff
//void read_course(Course & cs){
//    scanf("%s %d %d\n",cs.name,cs.deadline,cs.cost);
//fDddfdfdjjjJJjjJjJJjjjjJJJjJjJj
//int dp[NUM_3]
//
//void Buttom_Dowint couses,int day){
//    for (int i = 0; i <= day; ++i) {
//        //天数Dddddfssssjjjjjjf
//        for (int j = 0; j < couses; ++j) {
//            //遍历课程数
//        }fddisofsdioufsiofjiosfuiosgfiodsdufiofdsuofdosofdsofwaeagweo;gersi`IO2E1EWFOIW9DPUUYITVFFF`fe
//    }
//}
//
//int main(){
//
//}