#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
//二分搜索 O(logn)
int midsearch(int* a, int len, int target)
{
	sort(a, a + len);
	int l = 0;
	int r = len - 1;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == target)
		{
			return mid;
		}
		else if (a[mid] > target)
		{
			r = mid - 1;
		}
		else if(a[mid]<target){
			l= mid + 1;
		}
	}
	return 0;
}
//大整数乘法,O(nlog3)
int divide(int X, int Y, int n)
{
	int x = abs(X);
	int y = abs(Y);
	if (x == 0 || y == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return x * y;
	}
	else {
		int a = x / pow(10, n / 2);
		int b = x - a * pow(10, n / 2);
		int c = y / pow(10, n / 2);
		int d = y - c * pow(10, n / 2);
		int ac = divide(a, c, n / 2);
		int bd = divide(b, d, n / 2);
		int abcd = divide((a - b), (d - c), n / 2) + ac + bd;
		return ac * pow(10, n) + abcd * pow(10, n / 2) + bd;
	}
}
// strasswn矩阵乘法,O(nlog7)

//归并排序,O(nlogn)
void merge(int a[], int l[], int r[], int l1, int r1)
{
	int i = 0, j = 0, k = 0;
	while (i < l1 && j < r1)
	{
		if (l[i] < r[j])
		{
			a[k++] = l[i++];
		}
		else {
			a[k++] = r[j++];
		}
	}
	while (i < l1)
	{
		a[k++] = l[i++];
	}
	while (j < r1)
	{
		a[k++] = r[j++];
	}
}
void mergesort(int a[], int n)
{
	if (n > 1)
	{
		int mid = n / 2;
		int l[200];
		int r[200];
		for (int i = 0; i < mid; i++)
		{
			l[i] = a[i];
		}
		for (int j = mid; j < n; j++)
		{
			r[j - mid] = a[j];
		}
		mergesort(l, mid);
		mergesort(r, n - mid);
		merge(a, l, r, mid, n - mid);
		free(l);
		free(r);
	}
}
//快速排序,平均情况： T(n)= O(nlogn),O(n2)


void quicksort(int* arry, int l, int r)
{
	if (l > r)return;
	int temp = arry[l];
	int i = l;
	int j = r;
	while (i != j)
	{
		while (arry[j] >= temp&&j>i)
		{
			j--;
		}
		while (arry[i] <= temp&&j>i)
		{
			i++;
		}
		if (i < j)
		{
			int p = arry[i];
			arry[i] = arry[j];
			arry[j] = p;
		}
	}
	arry[l] = arry[i];
	arry[i] = temp;
	quicksort(arry, l, i - 1);
	quicksort(arry, i + 1, r);
}
//线性时间选择
//线性分解函数
int num[1000];
// 选择排序
void slsort(int p, int q)
{
	for (int i = p + 1; i <= q; i++)
	{
		int temp = num[i], j = i - 1;
		while (j >= p)
		{
			if (num[j] > temp)
			{
				num[j + 1] = num[j];
				j--;
			}
			else
				break;
		}
		num[j + 1] = temp;
	}
}
//选择函数
int partition(int p, int q, int mid)
{
	int i = p;
	int j = q;
	while (i <= q && j >= p)
	{
		while (num[i] < mid) { i++ };
		while (num[j] > mid) { j-- };
		if (i >= j)
		{
			break;
		}
		else {
			int temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			i++;
			j--;
		}
	}
	return j;
}
//选择函数
int select(int p, int q, int k)
{
	if (q = p < 75)
	{
		slsort(p, q);
		return num[p + k - 1];
	}
	//选出n/5组中的每组的中位数
	for (int i = 0; i <= (q - p - 4) / 5; i++)
	{
		slsort(p + 5 * i, p + 5 * i + 4);
		int temp = num[p + 5 * i + 2];
		num[p + 5 * i + 2] = num[p + i];
		num[p + i] = temp;
	}
	//选出各种中位数的中位数mid
	int mid = select(p, p + (q - p - 4) / 5, ((q - p - 4) / 5 + 1)) / 2;
	//以mid为基准进行分解
	int mid_id = partition(p, q, mid);
	int mid_rank = mid_id - p + 1;
	//递归条件判断
	if (k == mid_rank)
	{
		return num[mid_id];
	}
	else if (k < mid_rank)
	{
		return select(p, mid_id, k);
	}
	else {
		return select(mid_id + 1, q, k - mid_rank);
	}
};
int main()
{
	int res = divide(1234, 9876, 4);
	cout << res << endl;
	return 0;
}