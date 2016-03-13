#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node
{
	int a;
	void operator=(int v) { a = v; };
};

int cmp(Node & a, Node & b) {
	return a.a > b.a;
}

// int main() {
// 	Node a[100];
// 	for (int i = 0; i < 100; i++)
// 	{
// 		a[i] = 100-i;
// 
// 	}
// 	memset(a, 0, 100*sizeof(int));
// 	sort(a,a+100,cmp);
// 	for (int i = 0; i < 100; i++)
// 	{
// 		printf("%d\n", a[i]);
// 	}
// 	system("pause");
// 	return 0;
// }