#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
//���������
void select(int num, int s[], int f[]) {

	int preStart = 0;
	int preFinal = 2000;//��֤�����޴󼴿� 
	int i;
	int temp;
	int OK = 1;
	int sel[11];//�����������ݵĻ��� 
	int selNum = 0;


	while (OK) {
		OK = 0;
		for (i = 0; i < 11; i++) {

			if (f[i] < preFinal && s[i] >= preStart) {//Ѱ�ҿ�ʼʱ����ʵ�����½���ʱ�������� 
				preFinal = f[i];
				temp = i;
				OK = 1;
				printf("%d-------------->%d\n", s[i], f[i]);
			}
		}

		if (preFinal != 2000) {  //���������¸�ֵ 
			sel[selNum++] = temp;
			preStart = f[temp];
			preFinal = 2000;
		}
	}
	printf("%d", selNum);//�������� 
}
//��������(�Լ۱�)
void Sort(int n, float* w, float* v)//���յ�λ�����ļ�ֵ����С��������
{
	int i, j;
	float temp1, temp2;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)//ð������
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
	float w[100];//�������ÿ����Ʒ������
	float v[100];//�������ÿ����Ʒ�ļ�ֵ
	float x[100];//��ʾ�����뱳���ı���
	int n;//��Ʒ����
	float maxweight;//��������
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
	float c = maxweight;//���±�������
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
	//���,x[i]��ʾÿ����Ʒ�Ž�ȥ�ı���
}
//����װ������
void zhuangzai()
{
	int c, n;//c��ʾ��������n��ʾ��Ʒ��
	int sum = 0;//װ����Ʒ����Ŀ
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
//����������
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
//ֱ�Ӳ�������
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
	nq.push(p);//������
	while (nq.size() != 0)
	{
		node* cur = nq.front();
		nq.pop();//������
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
//��Դ���·��
int edge[550][550];  // ������еıߣ����� edges[i][j] �����i��j�ľ���
int dist[550];  // ��¼��ǰ���е㵽���ľ���
int visited[550];  // ��ǵ�ǰ�ĵ��Ƿ��߳�
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
//prim�㷨
const int MAXV = 1000; //��󶥵���
const int INF = 1000000000; //��INFΪһ���ܴ����

int n, m, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
int d[MAXV]; //�����뼯��S����̾���
bool vis[MAXV] = { false }; //������飬vis[i]==true��ʾ�ѷ��ʡ���ֵ��Ϊfalse

int prim() //Ĭ��0��Ϊ��ʼ�㣬����������С�������ı�Ȩ֮��
{
	fill(d, d + MAXV, INF); //fill����������d���鸳ΪINF
	d[0] = 0; //ֻ��0�Ŷ��㵽����S�ľ���Ϊ0������ȫ��INF
	int ans = 0; //�����С�������ı�Ȩ֮��
	for (int i = 0; i < n; i++) //ѭ��n��
	{
		int u = -1, MIN = INF; //uʹd[u]��С��MIN��Ÿ���С��d[u]
		for (int j = 0; j < n; j++) //�ҵ�δ���ʵĶ�����d[]��С��
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		//�Ҳ���С��INF��d[u]����ʣ�µĶ���ͼ���S����ͨ
		if (u == -1)
			return -1;
		vis[u] = true; //���uΪ�ѷ���
		ans += d[u]; //���뼯��S������С�ı߼�����С������
		for (int v = 0; v < n; v++)
		{
			//vδ���� && u�ܵ���v && ��uΪ�н�����ʹv�뼯��S����
			if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
			{
				d[v] = G[u][v]; //��G[u][v]��ֵ��d[v]
			}
		}
	}
	return ans; //������С�������ı�Ȩ֮��
}
int main()
{

	return 0;
}