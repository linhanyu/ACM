#include <cstdio>

const int MAXG = 2000000;

struct node{
    int key;
    int l;
    int r;
    int id;
} TG[MAXG];

struct Splaytree{
    int t;
    int num;

    Splaytree():t(-1),num(0){}

    void Insert(int key,int id){
        t = Insert(key,t,id);
    }

    int RightRotate(int t){
        int newt = TG[t].l;
        TG[t].l = TG[newt].r;
        TG[newt].r = t;

        return newt;
    }

    int LeftRotate(int t){
        int newt = TG[t].r;
        TG[t].r = TG[newt].l;
        TG[newt].l = t;

        return newt;
    }
    int Insert(int key, int t,int id){
        if (~t){
            if (key < TG[t].key){
                TG[t].l = Insert(key,TG[t].l,id);
                return RightRotate(t);
            } else if (key > TG[t].key){
                TG[t].r = Insert(key,TG[t].r,id);
                return LeftRotate(t);
            } else{
                return t;
            }
        } else{
            TG[num].l = TG[num].r = -1;
            TG[num].key = key;
            TG[num].id = id;
            return num++;
        }
    }
    void DeleteMin(){
        if (~t) t = DeleteMin(t);
        else puts("0");
    }

    int DeleteMin(int t){
        if (~TG[t].l){
            TG[t].l = DeleteMin(TG[t].l);
        } else{
            printf("%d\n",TG[t].id);
            return TG[t].r;
        }
        return t;
    }

    void DeleteMax(){
        if (~t) t = DeleteMax(t);
        else puts("0");
    }

    int DeleteMax(int t){
        if (~TG[t].r){
            TG[t].r = DeleteMax(TG[t].r);
        } else{
            printf("%d\n",TG[t].id);
            return TG[t].l;
        }
        return t;
    }
    void clear(){
        num = 0;
        t = -1;
    }

} tree;

void init(){
    tree.clear();
}
int main(){
    int op;
    init();
    while (~scanf("%d",&op) && op){
        if (op == 2){
            tree.DeleteMax();
        } else if (op == 3){
            tree.DeleteMin();
        } else{
            int id,p;
            scanf("%d%d",&id,&p);
            tree.Insert(p,id);
        }
    }

}