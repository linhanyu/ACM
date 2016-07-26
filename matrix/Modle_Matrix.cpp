//
// Created by Henry on 16/6/4.
//

#include <memory>
#include <iostream>

using namespace std;

template <class T> struct mart;
template <class T> ostream &operator << (ostream & os,mart<T> & mt);
template <class T> istream &operator << (istream & os,mart<T> & mt);

template <class T>
struct mart{
    int m,n;
    T ** ar;
    mart():m(0),n(0),ar(nullptr){}
    mart(int n,int m){
        ser_mart(n,m);
    }

    void ser_mart(int n,int m){
        this->m = m;
        this->n = n;
        ar = new T * [n];
        for (int i = 0; i < n; ++i) {
            ar[i] = new T[m];
            memset(ar[i],0, sizeof(T) * m);
        }
    }

    mart & sub_martrix(int begin_n,int end_n,int begin_m,int end_m){
        int len_n,len_m;
        len_n = end_n - begin_n +1;
        len_m = end_m - begin_m +1;
        mart * c= new mart(len_n,len_m);
        for (int i = 0; i < len_n; ++i) {
            for (int j = 0; j < len_m; ++j) {
                c->ar[i][j] += ar[begin_n + i -1][begin_m + j-1];
            }
        }

        return *c;
    }
    mart & multiply_squre(mart & mt){
        mart * c= new mart(n,mt.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mt.m; ++j) {
                for (int k  = 0; k < m; ++k) {
                    c->ar[i][j] += ar[i][k] * mt.ar[k][j];
                }
            }
        }

        return *c;
    }

    void set_element(int pos_n,int pos_m,mart & c,mart & tar){
        for (int i = 0; i < c.n; ++i) {
            for (int j = 0; j < c.m; ++j) {
                tar.ar[pos_n + i-1][pos_m + j-1] = c.ar[i][j];
            }
        }
    }

    mart & combine_four(mart & c11,mart & c12,mart & c21,mart & c22){
        int mid_n = c11.n;
        int mid_m = c11.m;
        int n = c22.n + mid_n;
        int m = c22.m + mid_m;
        mart * c = new mart(n,m);
        set_element(0,0,c11,*c);
        set_element(0,mid_m +1,c12,*c);
        set_element(mid_n + 1,0,c21,*c);
        set_element(mid_n + 1,mid_m +1,c22,*c);

        return *c;


    }
    mart & multiply_fast(mart & mt){
        if (m <=2 || n <= 2 || mt.m<=2 || mt.n<=2){
            return multiply_squre(mt);
        }
        mart a[2][2];
        mart b[2][2];
        mart s[10];
        mart p[7];

        int mid_a_n = n/2;
        int mid_a_m = m/2;
        int mid_b_n = mt.n/2;
        int mid_b_m = mt.m/2;
        a[0][0]= sub_martrix(0,mid_a_n,0,mid_a_m);
        a[0][1]= sub_martrix(mid_a_n+1,n,0,mid_a_m);
        a[1][0]= sub_martrix(0,mid_a_n,mid_a_m +1 ,m);
        a[1][1]= sub_martrix(mid_a_n+1,n,mid_a_m +1 ,m);
        b[0][0]= sub_martrix(0,mid_b_n,0,mid_b_m);
        b[0][1]= sub_martrix(mid_b_n+1,n,0,mid_b_m);
        b[1][0]= sub_martrix(0,mid_b_n,mid_b_m +1 ,m);
        b[1][1]= sub_martrix(mid_b_n+1,n,mid_b_m +1 ,m);

        s[0] = b[0][1] - b[1][1];
        s[1] = a[0][0] + a[0][1];
        s[2] = a[1][0] + a[1][1];
        s[3] = b[1][0] - b[0][0];
        s[4] = a[0][0] + a[1][1];
        s[5] = b[0][0] + b[1][1];
        s[6] = a[0][1] - a[1][1];
        s[7] = b[1][0] + b[1][1];
        s[8] = a[0][0] - a[1][0];
        s[9] = b[0][0] + b[0][1];

        p[0] = a[0][0] * s[0];
        p[1] = s[1] * b[1][1];
        p[2] = s[2] * b[0][0];
        p[3] = a[1][1] * s[3];
        p[4] = s[4] * s[5];
        p[5] = s[6] * s[7];
        p[6] = s[8] * s[9];

        return combine_four(p[4] +p[3]-p[1]+p[5],p[0]+p[1],p[2]+p[3],p[4]+p[1]-p[2]-p[6]);
    }
    mart &operator*(mart & mt){
        return multiply_fast(mt);
    }

    mart &operator+(mart & mt){
        mart * c= new mart(n,m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                    c->ar[i][j] += ar[i][j] * mt.ar[i][j];
            }
        }

        return *c;
    }

    mart &operator-(mart & mt){
        mart * c= new mart(n,m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                c->ar[i][j] += ar[i][j] - mt.ar[i][j];
            }
        }

        return *c;
    }

    void operator=(mart & mt){
        if (ar == nullptr){
            ser_mart(mt.n,mt.m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ar[i][j] = mt.ar[i][j];
            }
        }
    }

    friend ostream &operator << <>(ostream & os,mart & mt);
    friend istream &operator << <>(istream & os,mart & mt);

    ~mart(){
        for (int i = 0; i < n; ++i) {
            delete [] ar[i];
        }
        delete [] ar;
    }

};
template <class T>
ostream &operator <<(ostream & os,mart<T> & mt){
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            os<<mt.ar[i][j]<<" ";
        }
        os<<endl;

    }
    return os;
}

template <class T>
istream &operator >>(istream & is,mart<T> & mt){
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            is>>mt.ar[i][j];
        }

    }
    return is;
}

//
//int main(){
//    mart<int> a = mart<int >(3,3);
//    mart<int> b = mart<int >(3,3);
//
//    cin>>a;
//    cin>>b;
//    cout<<a*b;
//}
