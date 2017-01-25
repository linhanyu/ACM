//
// Created by Henry on 16/7/9.
//

#include <cstdio>
#include <memory>

#define NUM 131072
#define L_son(a) (a<<1)
#define R_son(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)

int XOR[NUM<<2];
int cover[NUM<<2];
bool hash[NUM];
char op;

void FXOR(int rt){
    if (cover[rt]!=-1){
        cover[rt] ^= 1;
    } else{
        XOR[rt] ^= 1 ;
    }
}

void Push_Down(int rt){
    if (cover[rt] != -1){
        cover[L_son(rt)] = cover[R_son(rt)] = cover[rt];
        XOR[L_son(rt)] = XOR[R_son(rt)] = 0;
        cover[rt] = -1;
    }

    if (XOR[rt]){
        FXOR(L_son(rt));
        FXOR(R_son(rt));
        XOR[rt] = 0;
    }
}

void update(int left,int right,int L_bound,int R_bound,int rt){
    if (L_bound <= left && right<=R_bound){
        if (op == 'U'){
            cover[rt] = 1;
            XOR[rt] = 0;
        } else if(op == 'D'){
            cover[rt] = 0;
            XOR[rt] = 0;
        } else if(op == 'C' || op == 'S'){
            FXOR(rt);
        }
        return;
    }

    Push_Down(rt);
    int m = MID(left,right);
    if (L_bound<= m){
        update(left,m,L_bound,R_bound,L_son(rt));
    } else if(op == 'I' || op == 'C'){
        XOR[L_son(rt)] = cover[L_son(rt)] = 0;

    }
    if (R_bound > m){
        update(m+1,right,L_bound,R_bound,R_son(rt));
    } else if(op == 'I' || op == 'C'){
        XOR[R_son(rt)] = cover[R_son(rt)] = 0;

    }


}


void query(int left,int right, int rt){
    if (cover[rt] == 1){
        for (int it = left ; it <= right ; it ++) {
            hash[it] = true;
        }
        return ;

    } else if(cover[rt] == 0){
        return;
    }
    if (left == right) return;
    Push_Down(rt);

    int mid = MID(left,right);
    query(left,mid,L_son(rt));
    query(mid+1,right,R_son(rt));

}
int main(){
    char l_bracket,r_bracket;
    int l,r;
    XOR[1] = cover[1] = 0;

    memset(hash,0, sizeof(hash));
    while (scanf("%c %c%d,%d%c\n",&op,&l_bracket,&l,&r,&r_bracket)!=EOF ){
        l<<=1;
        r<<=1;
        //离散化
        if (l_bracket == '('){
            l++;
        }

        if (r_bracket == ')'){
            r--;
        }

        if (l>r){
            if (op == 'C' || op == 'I') {
                cover[1] = XOR[1] = 0;
            }

        } else{
            update(0,NUM,l,r,1);
        }
    }
    query(0,NUM,1);
    bool flag = false;
    int s = -1 , e;
    for (int i = 0; i <= NUM; ++i) {
        if (hash[i]){
            if (s == -1){
                s=i;
            }
            e=i;
        } else{
            if (s != -1) {
                if (flag) printf(" ");
                flag = true;
                printf("%c%d,%d%c",s&1?'(':'[' , s>>1 , (e+1)>>1 , e&1?')':']');
                s = -1;
            }
        }

    }
    if (!flag) printf("empty set");
    puts("");
    return 0;

}

