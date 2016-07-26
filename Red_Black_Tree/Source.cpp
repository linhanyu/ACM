//
// Created by Henry on 16/7/4.
//

#include <iostream>

using namespace std;

enum COLOR{RED,BLACK};


struct RB_Node{
    int key;
    RB_Node * parent;
    RB_Node * left;
    RB_Node * right;
    COLOR color;
    int count ;
};


struct Tree{
    RB_Node * root;
    RB_Node * nill;

    Tree(){
        nill = new RB_Node();
        nill->left = nill;
        nill->right = nill;
        nill->parent = nill;
        nill->color = BLACK;
        root = nill;
    }

    void Destory(RB_Node * t){
        if(t == nill){
            return;
        }

        Destory(t->left);
        Destory(t->right);
        delete t;
    }
    ~Tree(){
        Destory(root);
        delete nill;
    }
};

void left_rotate(Tree & T,RB_Node * x){
    RB_Node * y = x->right;
    x->right = y->left;

    if(y->left != T.nill){
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == T.nill) {
        T.root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else{
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void right_rotate(Tree & T,RB_Node * x){
    RB_Node * y = x->left;
    x->left = y->right;

    if(y->right != T.nill){
        y->right->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == T.nill){
        T.root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else{
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void R_B_FIX(Tree & T,RB_Node * z){
    RB_Node * y;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            //左树
            y = z->parent->parent->right;// 祖父节点的右树
             if(y->color == RED){
                 y->color = BLACK;
                 z->parent->color = BLACK;
                 z->parent->parent->color = RED;
                 z = z->parent->parent;
             } else {
                 if(z == z->parent->right){
                     z = z->parent;
                     left_rotate(T,z);
                 }

                 z->parent->color = BLACK;
                 z->parent->parent->color = RED;
                 right_rotate(T,z->parent->parent);

             }
        } else{
            y = z->parent->parent->left;
            if(y->color == RED){
                y->color = BLACK;
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else{
                if(z == z->parent->left){
                    z = z->parent;
                    right_rotate(T,z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(T,z->parent->parent);
            }

        }
    }
    T.root->color = BLACK;
}

void Insert(Tree & T,RB_Node * z){
    RB_Node * x = T.root;
    RB_Node * y = T.nill;
    while (x != T.nill){
        y = x;
        if(z->key < x->key){
            x = x->left;
        } else if(z->key > x->key){
            x = x->right;
        } else{
            x->count++;
            return;
        }

    }
//撸到叶节点
    z->parent = y;
    if(y == T.nill){
        T.root = z;
    } else if(z->key < y->key){
        y->left = z;
    } else{
        y->right = z;
    }

    R_B_FIX(T,z);

}
template <class T>
RB_Node * Create_Node(Tree & tree,T key){
    RB_Node * rb = new RB_Node();
    rb->left = tree.nill;
    rb->right = tree.nill;
    rb->parent = tree.nill;
    rb->color = RED;
    rb->count = 1;
    rb->key = key;
    return rb;

}

void tra(Tree & T,RB_Node * tree,int level){
    if(tree == T.nill){
        return;
    }

    tra(T,tree->left,level+1);
    cout<<tree->key <<":" << level<<endl;
    tra(T,tree->right,level+1);

}

void RB_Transplant(Tree & t,RB_Node * u,RB_Node * v){
    if (u->parent == t.nill){
        t.root = v;
    } else if(u == u->parent->left){
        u->parent->left = v;
    } else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

RB_Node * Min_Tree(Tree & t,RB_Node * nd){
    while(nd->left != t.nill)
        nd = nd->left;
    return nd;
}

void RB_Delete_Fix(Tree & t,RB_Node * x){
    RB_Node * w;
    while (x != t.root && x->color == BLACK){
        if (x == x->parent->left){
            //左树
            w = x->parent->right;
            if (w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(t,x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            } else{
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(t,w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(t,x->parent);
                x= t.root;
            }

        }else{
            //右树
            w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(t,x->parent);
                w = x->parent->left;
            }

            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            } else{
                if (w->left->color == BLACK){
                    w->color = RED;
                    w->right->color = BLACK;
                    left_rotate(t,w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(t,x->parent);
                x = t.root;
            }
        }
    }
}

void RB_Dlete(Tree & t,RB_Node * z){
    RB_Node * y = z;
    RB_Node * x;
    COLOR y_original_color = y->color;

    if (z->left == t.nill){
        x = z->right;
        RB_Transplant(t,z,z->right);
    } else if(z->right == t.nill){
        x = z->left;
        RB_Transplant(t,z,z->left);
    } else{
//从右边挑
        y = Min_Tree(t,z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z){
            x->parent = y;
        } else{
            RB_Transplant(t,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        RB_Transplant(t,z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;

    }

    if (y_original_color == BLACK){
        R_B_FIX(t,x);
    }
    delete z;
}

RB_Node * fine(Tree & tr,int key){
    RB_Node * x = tr.root;
    while(x != tr.nill){
        if (key < x->key){
            x = x->left;
        } else if(key > x->key){
            x = x->right;
        } else{
            return x;
        }
    }
    return tr.nill;
}
int main(){
    Tree tr;

    for (int i = 0; i < 10; ++i) {
        Insert(tr,Create_Node(tr,i));
    }
    RB_Dlete(tr,fine(tr,4));
    RB_Dlete(tr,fine(tr,3));
    RB_Dlete(tr,fine(tr,2));

//    fine(tr,4);
    tra(tr,tr.root,0);

}