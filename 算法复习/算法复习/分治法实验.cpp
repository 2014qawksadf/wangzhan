#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int maxnumber;
int zhongshu;
void maxchongfu(vector<int>& arry, int l,int r)
{
	int cnt = 0;
	int mid = (l + r) / 2;
	int i, j;
	for (i = mid; i>=0; i--)
	{
		if (arry[i] == arry[mid])
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	for (j = mid + 1; j <=r; j++)
	{
		if (arry[j] == arry[mid])
		{
			cnt++;
		}
		else {
			break;
		}
	}
	if (cnt > maxnumber)
	{
		zhongshu = arry[mid];
		maxnumber = cnt;
	}
	if (i - l > maxnumber) {
		maxchongfu(arry, l, i);
	}
	if (r - j > maxnumber)
	{
		maxchongfu(arry, j, r);
	}
}
int main()
{
	int num, temp;
	vector<int>res;
	ifstream fin("C:\\Users\\admin\\Desktop\\shiyan\\众数问题 input 1.txt");
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		fin >> temp;
		res.push_back(temp);
	}
	sort(res.begin(),res.end());
	maxchongfu(res, 0, num-1);
	cout <<"众数为"<< zhongshu << endl;
	cout <<"重数为" <<maxnumber << endl;
	cout << endl;
	res.clear();
	zhongshu = 0;
	maxnumber = 0;
	ifstream fin1("C:\\Users\\admin\\Desktop\\shiyan\\众数问题 input 2.txt");
	fin1 >> num;
	for (int i = 0; i < num; i++)
	{
		fin1 >> temp;
		res.push_back(temp);
	}
	sort(res.begin(), res.end());
	maxchongfu(res, 0, num - 1);
	cout << "众数为" << zhongshu << endl;
	cout << "重数为" << maxnumber << endl;
	return 0;
}