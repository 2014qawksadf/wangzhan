#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//最长公共子序列
int longest(string s1,string s2)
{
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1,0));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1]+1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];
}
//最大字段和
int zuida(vector<int>& num)
{
	vector<int>dp(num.size());
	dp[0] = num[0];
	int res = dp[0];
	for (int i = 1; i < num.size(); i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		if (dp[i] > res)
		{
			res = dp[i];
		}
	}
	return res;
}
//0-1背包问题
int bag(vector<int>& weight, vector<int>& value,int maxweight)
{
	vector<vector<int>>dp(weight.size(), vector<int>(maxweight + 1, 0));
	for (int i = weight[0]; i <= maxweight; i++)
	{
		dp[0][i] = value[0];
	}
	for (int i = 1; i < weight.size(); i++)
	{
		for (int j = 0; j <=maxweight; j++)
		{
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]);
			}
		}
	}
	return dp[weight.size() - 1][maxweight];
}
//租用游艇问题
int mincost(int* cost,int n)
{
	int dp[100][100];
	int i, j, k;
	int flag = n - 1;
	j = n;
	for (i = n - 2; i >= 1; i--)
	{
		for (k = flag; k <= n - 1; k++)
		{
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
		flag--;
	}
	return dp[1][j];
}
int main()
{
	return 0;
}