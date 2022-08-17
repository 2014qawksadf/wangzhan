#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[200][200];
int mincost(int n) {
	int i, j, k;                                      
	int flag = n - 1;                                    
	j = n;                                               
	for (i = n - 2; i >= 1; i--) {                        
		for (k = flag; k <= n - 1; k++)
		{
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
		flag--;
	}
	return dp[1][n];                          
}
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\admin\Desktop\\shiyan\\租用游艇问题 input 2.txt");
	int n;
	fin >> n;
	int j;
	int k = 2;
	for (int i = 1; i < n; i++)
	{
		for (j = k; j <=n; j++)
		{
			fin >> dp[i][j];
			cout << dp[i][j] << endl;
		}
		k++;
	}
	int m = mincost(n);
	cout << m << endl;
	return 0;
}