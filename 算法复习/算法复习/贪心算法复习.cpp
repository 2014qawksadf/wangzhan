#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
//活动安排问题
void select(int num, int s[], int f[]) {

	int preStart = 0;
	int preFinal = 2000;//保证是无限大即可 
	int i;
	int temp;
	int OK = 1;
	int sel[11];//用来储存相容的活动编号 
	int selNum = 0;


	while (OK) {
		OK = 0;
		for (i = 0; i < 11; i++) {

			if (f[i] < preFinal && s[i] >= preStart) {//寻找开始时间合适地情况下结束时间最早者 
				preFinal = f[i];
				temp = i;
				OK = 1;
				printf("%d-------------->%d\n", s[i], f[i]);
			}
		}

		if (preFinal != 2000) {  //变量的重新赋值 
			sel[selNum++] = temp;
			preStart = f[temp];
			preFinal = 2000;
		}
	}
	printf("%d", selNum);//相容数量 
}
//背包问题(性价比)
void Sort(int n, float* w, float* v)//按照单位重量的价值量大小进行排序
{
	int i, j;
	float temp1, temp2;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)//冒泡排序
		{
			temp1 = v[i] / w[i];
			temp2 = v[i + 1] / w[i + 1];
			if (temp1 < temp2)
			{
				swap(w[i], w[i + 1]);
				swap(v[i], v[i + 1]);
			}
		}
	}
}
void beibao()
{
	float w[100];//用来存放每个物品的重量
	float v[100];//用来存放每个物品的价值
	float x[100];//表示最后放入背包的比例
	int n;//物品件数
	float maxweight;//背包容量
	cin >> n >> maxweight;
	for (int i = 1; i <= n; i++)
	{
		float temp1, temp2;
		cin >> temp1 >> temp2;
		w[i] = temp1;
		v[i] = temp2;
	}
	Sort(n, w, v);
	for (int i = 1; i <= n; i++)
	{
		x[i] = 0;
	}
	float c = maxweight;//更新背包容量
	int i;
	for (i = 1; i <= n; i++)
	{
		if (c < w[i])break;
		x[i] = 1;
		c = c - w[i];
	}
	if (i <= n)
	{
		x[i] = c / w[i];
	}
	//输出,x[i]表示每件物品放进去的比例
}
//最优装载问题
void zhuangzai()
{
	int c, n;//c表示载重量，n表示物品数
	int sum = 0;//装入物品的数目
	int temp;
	int w[100];
	for (int i = 1; i <= n; i++)
	{
		int pp;
		cin >> pp;
		w[i] = pp;
	}
	sort(w + 1, w + n + 1);
	for (int i = 1; i <= n; i++)
	{
		temp += w[i];
		if (temp < c)
		{
			break;
		}
		else {
			sum++;
		}
	}
	cout << sum << endl;
}
//哈夫曼编码
class node
{
public:
	node(string con, float wht, node* left, node* right, string co)
	{
		content = con;
		weight = wht;
		leftchild = left;
		rightchild = right;
		code = co;
	}
	string content;
	float weight;
	node* leftchild;
	node* rightchild;
	string code;
};

void insertion_sort(node** array, int low, int high)
//直接插入排序
{
	for (int i = low + 1; i < high; i++)
	{
		node* tem = array[i];
		int j = i - 1;
		while (array[j]->weight > tem->weight && j >= low)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tem;
	}
}

void create_huffman_tree(string* s, float* w, int n, node** array)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = new node(s[i], w[i], NULL, NULL, "");
	}
	insertion_sort(array, 0, n);
	int p = 0;
	while (p != n - 1)
	{
		node* min_1 = array[p];
		node* min_2 = array[p + 1];
		node* new_node = new node("", min_1->weight + min_2->weight, min_1, min_2, "");
		array[p + 1] = new_node;
		p = p + 1;
		insertion_sort(array, 0, n);
	}

}

void create_huffman_code(node* p)
{
	queue<node*> nq;
	nq.push(p);//进队列
	while (nq.size() != 0)
	{
		node* cur = nq.front();
		nq.pop();//出队列
		node* l = cur->leftchild;
		if (l != NULL)
		{
			l->code = cur->code + "0";
			nq.push(l);
		}
		node* r = cur->rightchild;
		if (r != NULL)
		{
			r->code = cur->code + "1";
			nq.push(r);
		}
		if (l == NULL && r == NULL)
		{
			cout << cur->content << ": " << cur->code << endl;
		}
	}
}
//单源最短路径
int edge[550][550];  // 存放所有的边，例如 edges[i][j] 代表从i到j的距离
int dist[550];  // 记录当前所有点到起点的距离
int visited[550];  // 标记当前的点是否被踢出
void dj(int n,int vs)
{
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
		dist[i] = edge[vs][i];
	}
	visited[vs] = 1;
	dist[vs] = 0;
	int k;
	for (int i = 1; i < n; i++)
	{
		int min = 1000;
		for (int j = 0; j < n; i++)
		{
			if (!visited[j] && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		visited[k] = 1;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] > dist[k] + edge[k][j])
			{
				dist[j] = dist[k] + edge[k][j];
			}
		}
	}
}
//prim算法
const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数

int n, m, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //顶点与集合S的最短距离
bool vis[MAXV] = { false }; //标记数组，vis[i]==true表示已访问。初值均为false

int prim() //默认0号为初始点，函数返回最小生成树的边权之和
{
	fill(d, d + MAXV, INF); //fill函数将整个d数组赋为INF
	d[0] = 0; //只有0号顶点到集合S的距离为0，其余全是INF
	int ans = 0; //存放最小生成树的边权之和
	for (int i = 0; i < n; i++) //循环n次
	{
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
		for (int j = 0; j < n; j++) //找到未访问的顶点中d[]最小的
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，则剩下的顶点和集合S不连通
		if (u == -1)
			return -1;
		vis[u] = true; //标记u为已访问
		ans += d[u]; //将与集合S距离最小的边加入最小生成树
		for (int v = 0; v < n; v++)
		{
			//v未访问 && u能到达v && 以u为中介点可以使v离集合S更近
			if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
			{
				d[v] = G[u][v]; //将G[u][v]赋值给d[v]
			}
		}
	}
	return ans; //返回最小生成树的边权之和
}
int main()
{

	return 0;
}