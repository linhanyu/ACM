#include <cstdio>
#include <iostream>
#include <cstdlib>
#define NUM 101
using namespace std;

template<class T>
void Insert_Sort(T * a, int size) {
	int i, j;
	T temp;
	for ( i = 1; i < size; i++)
	{
		temp = a[i];
		for (j = i;j>0 && temp < a[j-1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

struct T_v
{
	int end;
	int begin;
	bool operator<(T_v & b) { return end < b.end; }

};

istream & operator>>(istream & is, T_v & tv) {
	is >> tv.begin >> tv.end;
	return is;
}

// int main() {
// 
// 	int n;
// 	T_v prog[NUM];
// 	while (cin >> n && n!=0)
// 	{
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> prog[i];
// 		}
// 
// 		Insert_Sort(prog, n);
// 
// 		int max = 0,sum=0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (prog[i].begin >= max)
// 			{
// 				sum++;
// 				max = prog[i].end;
// 			}
// 		}
// 
// 		cout << sum << endl;
// 	}
// }