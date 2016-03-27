#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
#define NUM 9000
#define BASE 1000000
#define BIT 6

void g_deal(long long * num, int & len) {
	long long g;
	int i;
	for (i = 0, g = 0; i < len || g != 0; i++)
	{
		num[i] += g;
		g = num[i] / BASE;
		num[i] %= BASE;
	}
	len = max(len,i);
}

void BigNumMulty(long long * num, int n, int & len) {
	for (int i = 0; i < len; i++)
	{
		num[i] *= n;
	}

	g_deal(num, len);
}



void prt_BigInt(long long * num, int len,ostream & os) {
	os << num[len - 1];
	for (int i = len - 2; i >= 0;i--)
	{
		os << setw(BIT) << setfill('0') << num[i];
	}
}
// int main() {
// 	int len,n;
// 	long long num1[NUM];
// 	while (cin >> n)
// 	{
// 		memset(num1, 0, sizeof(num1));
// 		num1[0] = n;
// 		len = 1;
// 		for (int j = n-1; j >1; j--)
// 		{
// 			BigNumMulty(num1, j, len);
// 		}
// 
// 		prt_BigInt(num1, len, cout);
// 		cout << endl;
// 	}
// }