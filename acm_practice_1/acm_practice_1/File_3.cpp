#include <iostream>
#include <cstdio>

#define NUM 1001

using namespace std;

template<class T>
void Insert_sort(T * a, int size) {
	int i, j;
	T temp;
	for ( i = 1; i < size; i++)
	{
		temp = a[i];
		for  (j = i; j >0 && temp<a[j-1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}

}


struct cangku
{
	int java_bean;
	int food;
	double division;

	void set_cangku(int a, int b){
		java_bean = a;
		food = b;
		division = (double)a / b;
	}

	bool operator<(cangku & ck) { return division > ck.division; }
};

// /*int main()*/ {
// 	cangku Cangku[NUM];
// 	int m, n;
// 	int j, f;
// 	double sum;
// 	while (cin>>m>>n && (m!=-1 || n!=-1))
// 	{
// 		sum = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> j >> f;
// 			Cangku[i].set_cangku(j, f);
// 		}
// 		Insert_sort(Cangku, n);
// 
// 		for (int i = 0; i < n;i++)
// 		{
// 			if (m >= Cangku[i].food)
// 			{
// 				m -= Cangku[i].food;
// 				sum += Cangku[i].java_bean;
// 			}
// 			else
// 			{
// 				sum += Cangku[i].division * m;
// 				m = 0;
// 			}
// 		}
// 
// 		printf("%.3lf\n", sum);
// 	}
// }