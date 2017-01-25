//
// Created by Henry on 16/8/2.
//
#include <cstdio>
#include <memory>
#include <algorithm>

#define NUM 1001
#define NEGINF -3000000

using namespace std;

struct Node{
    int l;
    int h;
};

int zeroOneMaxArea(bool (*map)[NUM],int m,int n){
    static Node stack[NUM+10];
    static int l[NUM];
    static int h[NUM];

    memset(h,0, sizeof(h));
    int ans = -1;
    for (int i = 1; i <= m; ++i) {
        int top = 0;
        //i行
        for (int j = 1; j <=  n; ++j) {
            //j列
            if (map[i][j]){
                //滚动数组.把第j列从上到下连续者相加
                h[j]++;
            } else{
                h[j] = 0;
            }
            //将连续递增的矩形入栈.当出现矮边界时退栈,计算矩形面积
            if(top && stack[top].h > h[j]){
                //如果栈顶元素高度大于第i行j列的连续高度
                while(top && stack[top].h > h[j]){
                    ans = max(ans,stack[top].h * (j-stack[top].l));
                    //不包括j
                    top--;
                }
                stack[++top].h = h[j];
            }else{
                stack[++top].h = h[j];
                stack[top].l = j;
                if (top >=2 && stack[top-1].h == stack[top].h) stack[top].l = stack[top-1].l;
                //数字一样,则并入同一矩形.把最大高度入栈
            }

        }

        while(top)
        {
            ans=max(ans,stack[top].h*(n+1 - stack[top].l));
            top--;
            //处理边界
        }
    }

    return ans;



}



int main(){
    int t,n,m;
    bool map[NUM][NUM];
    char tmp[3];
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&n,&m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ; j++) {
                scanf("%s",tmp);
                switch (tmp[0]){
                    case 'R':
                        map[i][j] = false;
                        break;
                    case 'F':
                        map[i][j] = true;
                        break;
                    default:;

                }

           }
        }

        printf("%d\n",zeroOneMaxArea(map,n,m)*3);



    }
}
