// #include <stdio.h>
// #include <algorithm>
// 
// using namespace std;
// 
// 
// #define NUM 3001
// #define CUFOFF 9
// 
// void Insert_sort(int * a, int size) {
// 	int i, j;
// 	int temp;
// 	for (i = 1; i < size; i++)
// 	{
// 		temp = a[i];
// 		for (j = i; j > 0 && temp < a[j - 1]; j--)
// 		{
// 			a[j] = a[j - 1];
// 		}
// 		a[j] = temp;
// 	}
// 
// }
// 
// int median_3(int left, int right, int *a)
// {
// 	int mid = (left + right) >> 1;
// 	if (a[left] > a[mid])
// 	{
// 		swap(a[left], a[mid]);
// 	}
// 	if (a[mid] > a[right])
// 	{
// 		swap(a[right], a[mid]);
// 	}
// 	if (a[left] > a[mid])
// 	{
// 		swap(a[left], a[mid]);
// 	}
// 
// 	swap(a[mid], a[right - 1]);
// 	return a[right - 1];
// 
// 
// }
// 
// void Q_Sort(int * a, int left, int right) {
// 	if (CUFOFF + left < right)
// 	{
// 		int pivot = median_3(left, right, a);
// 		int i = left;
// 		int j = right - 1;
// 
// 		while (true)
// 		{
// 			while (a[++i] < pivot);
// 			while (a[--j] > pivot);
// 
// 			if (i<j)
// 			{
// 				swap(a[i], a[j]);
// 			}
// 			else
// 			{
// 				break;
// 			}
// 
// 		}
// 
// 		swap(a[i], a[right - 1]);
// 		Q_Sort(a,left, i-1);
// 		Q_Sort(a,i + 1, right);
// 	} 
// 	else
// 	{
// 		Insert_sort(a + left, right - left + 1);
// 
// 	}
// 
// 
// }

// int main() {
// 	int n, temp,max,t;
// 	int solder[NUM];
// 
// // 	while (cin>>n)
// // 	{
// // 		memset(solder, 0, sizeof(int) * NUM);
// // 		for (int i = 0; i < n;i++)
// // 		{
// // 			cin >> temp;
// // 			solder[temp]++;
// // 		}
// // 		
// // 		max = 0;
// // 		for (int i = 0; i < NUM; i++)
// // 		{
// // 			if (solder[i] > max)
// // 			{
// // 				max = solder[i];
// // 			}
// // 		}
// // 
// // 
// // 		cout << max << endl;
// // 
// // 		
// // 	}
// 	while (scanf_s("%d",&n)!=EOF)
// 	{
// 		
// 		for (int i = 0; i < n;i++)
// 		{
// 			scanf_s("%d", &solder[i]);
// 		}
// 
// 		Q_Sort(solder,0,n-1);
// 		
// 		max = 1;
// 		t = 1;
// 		for (int i = 1; i < n;i++)
// 		{
// 			if (solder[i] != solder[i - 1]) {
// 				t = 1;
// 			}
// 			else if (++t > max) max = t;
// 		}
// 
// 		printf("%d\n", max);
// 	}
// }



