//
// Created by Henry on 16/9/5.
//

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//#include <sstream>
//using namespace std;
//
//const char * dirs= "NESW";
//const char * turns = "FLR";
//const int TITLESIZE = 30;
//const int MAXN = 9
//bool hasedge[MAXN][MAXN][4][3];
////9行,9列,4个方向,3种转向
//int dis[MAXN][MAXN][4];
//
////9行,9列,面向4种朝向
//
//struct Node{
//    int dir;
//    int r;
//    int c;
//    Node(int r,int c,int dir):r(r),c(c),dir{dir}{}
//};
//
//int dirScrip(char c){ return strchr(dirs,c) - dirs;}
//int turnScrip(char c){ return strchr(turns,c) - turns;}
//
//const int dr[] = {-1,0,1,0};
//const int dc[] = {0,1,0,-1};
////与die映射
//Node * p[MAXN][MAXN][4];
//
//Node * walk(const Node * u,int turn){
//    int dir = u->dir;
//    if(turn == 1) dir = (dir+3)%4;
//        //左
//    if(turn == 2) dir = (dir+1)%4;
//    return new Node(u->r + dr[dir],u->c + dc[dir],dir);
//}
//
//void initdis(int val){
//    for (int i = 0; i < MAXN; ++i) {
//        for (int j = 0; j < MAXN; ++j) {
//            for (int k = 0; k < 4; ++k) {
//                dis[i][j][k] = val;
//            }
//        }
//    }
//}
//
//string Title;
//const string E("END");
//int r1,c1,dir,r2,c2;
//bool inside(int r,int c){}
//
//bool readIn(){
//    getline(cin,Title);
//    if (Title == E) return false;
//
//    string tmp;
//    getline(cin,tmp);
//    char d;
//    stringstream ss(tmp);
//    ss>>r1>>c1>>d>>r2>>c2;
//    dir = dirScrip(d);
//
//    while(true){
//        string tmp;
//        getline(cin,tmp);
//        if (tmp[0] == '0') break;
//        int r,c;
//        char d[8];
//        stringstream ss(tmp);
//        ss>>r>>c;
//
//        while(true){
//            cin>>d;
//
//            if (d[0] == '*') break;
//            int tmpdir = dirScrip(d[0]);
//            for (int i = 1; i < strlen(d); ++i) {
//                hasedge[r][c][tmpdir][turnScrip(d[i])] = true;
//            }
//        }
//
//    }
//
//}
//
//void C(queue<Node *> & Q){
//    while (!Q.empty()){
//        Node * g = Q.front();
//        Q.pop();
//        delete g;
//    }
//}
//
//void BFS(){
//    queue<Node *> Q;
//    queue<Node *> clear;
//    initdis(-1);
//    Node * begin = new Node(r1,c1,dir);
//    dis[r1][c1][dir] = 0;
//    Q.push(begin);
//    while (!Q.empty()){
//        Node * u = Q.front();
//        clear.push(u);
//        Q.pop();
//
//        if (u->r == r2 && u->c == c2){
//            C(clear);
//            return;
//        }
//
//        for (int i = 0; i < 3; ++i) {
//            Node * v = walk(u,turns[i]);
//            if (hasedge[u->r][u->c][u->dir][i] && inside(v->r,v->c) && dis[v->r][v->c][v->dir] < 0){
//                dis[v->r][v->c][v->dir] = dis[u->r][u->c][u->dir] + 1;
//                p[v->r][v->c][v->dir] = u;
//                Q.push(v);
//            }
//        }
//
//    }
//
//    C(clear);
//    puts("No Solution Possible");
//
//
//}