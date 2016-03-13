#include <iostream>

using namespace std;


#define NUM 100

template<class T>
void Insert_Sort(T * a,int size) {
	int i, j;
	T temp;
	for (i = 1; i < size; i++)
	{
		temp = a[i];
		for  (j = i; j > 0 && temp < a[j-1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

struct treasure
{
	int v;
	int val;
	int division;
	void set_treasure(int a, int b) { v = b; division = a; val = division*v; }
	bool operator<(treasure & tr) { return division > tr.division; }
};

// int main() {
// 	int v, n,sum;
// 	int pi, mi;
// 	treasure trs[NUM];
// 	while (cin>>v && v)
// 	{
// 		cin >> n;
// 		sum = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> pi >> mi;
// 			trs[i].set_treasure(pi, mi);
// 		}
// 
// 		Insert_Sort(trs, n);
// 
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (trs[i].v > v)
// 			{
// 				sum += trs[i].division * v;
// 				break;
// 			} 
// 			else
// 			{
// 				v -= trs[i].v;
// 				sum+=trs[i].val;
// 			}
// 		}
// 
// 		cout << sum << endl;
// 		
// 	}
// 
// }