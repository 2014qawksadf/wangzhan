#include <iostream>
#include <string>
using namespace std;
int aver;
template<class type1, class type2>
void fun(type1 x, type2 y)
{
	cout << x << " " << y << endl;
}
class stu {
private:
	int x;
	int y;
public:
	stu(int a, int b)
	{
		x = a;
		y = b;
	}
	int operator>(stu& stu1);
	void showx()
	{
		cout << x << endl;
	}
};
int stu::operator>(stu& stu1)
{
	if (x + y > stu1.x + stu1.y)
	{
		return 1;
	}
	return 0;
}
template <class pp>
pp& max(pp& x1, pp& y1)
{
	if (x1 > y1)
	{
		return x1;
	}
	return y1;
}
template <class type>
class peo {
private:
	type sum;
public:
	peo(type name)
	{
		sum = name;
	}
	type returnsum();
};
template<class type>
type peo<type>::returnsum()
{
	cout << "请输入一个字" << endl;
	int x;
	cin >> x;
	if (x < 1)
	{
		return 0;
	}
	return sum;
}
const int num1 = 10;
class coord {
private:
	int x;
	int y;
public :
	coord(int a, int b)
	{
		x = a;
		y = b;
	}
	coord(const coord& p)
	{
		x = 2 * p.x;
		y = 2 * p.y;
	}
	void print();
};
void coord::print()
{
	cout << x << endl;
	cout << y << endl;
}
class A {
private:
	int x;
public:
	A(int m)
	{
		x = m;
	}
	void dis()
	{
		cout << "this" << this << this->x << endl;
	}
};
class cao {
private:
	int x;
	int y;
public:
	void fuzhi(int a, int b)
	{
		x = a;
		y = b;
	}

	void show()
	{
		cout << x << endl;
	}
};
class student {
private:
	int score;
	static int sum;
public:
	student(int num)
	{
		score = num;
		sum += score;
	}
	void show()
	{
		cout << sum << endl;
	}
};
int student::sum = 0;
class girl;
class boy {
private:
	string name;
	int age;
public:
	boy(string name1, int age1)
	{
		name = name1;
		age = age1;
	}
	void show(girl&);
};
class girl {
private:
	string name;
	int age;
public:
	girl(string name1, int age1)
	{
		name = name1;
		age = age1;
	}
	friend void boy::show(girl&);
};
void boy::show(girl& p)
{
	cout << p.name << endl;
	cout << p.age << endl;
}
class pp {
private:
	int score;
public:
	pp(int n)
	{
		score = n;
	}
	pp operator++(int);
	void show()
	{
		cout << score;
	}
};
pp pp::operator++(int)
{
	++score;
	return *this;
}
class V {
private:
	int x;
public:
	V(int m)
	{
		x = m;
	}
	virtual void show()
	{
		cout << x << endl;
	}
};
class i :public V {
private:
	int num;
public:

	i(int a, int b) :V(a) {
		num = b;
	}
	virtual void show()
	{
		cout << num << endl;
	}
};
class Sample
{
	int A;
	static int B;
public:
	Sample(int a) { A = a, B += a; }
	static void func(Sample s);
};
void Sample::func(Sample s)
{
	cout << "A=" << s.A << ",B=" << B << endl;
}
int Sample::B = 0;
class complex {
private:
	int a;
	int b;
public:
	complex(int a1=0, int b1=0)
	{
		a = a1;
		b = b1;
	}
	friend complex operator+(complex& num,complex &num1);
	void show()
	{
		cout << a << endl;
	}
};
complex operator+(complex& num, complex& num1)
{
	return complex(num.a + num1.a, num.b + num1.b);
}
class cord {
private:
	int x;
	int y;
public:
	cord(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	friend cord operator++(cord &num,int);
	void show()
	{
		cout << x << endl;
		cout << y << endl;
	}
};
cord operator++(cord& num1, int)
{
	return cord(num1.x + 1, num1.y + 1);
}
class shape {
public:
	virtual void pointarea() = 0;//纯虚函数
};
class circle {
	const float pi=3.14;
	int r;
public:
	circle(int m)
	{
		r = m;
	}
	void pointarea()
	{
		cout << pi * r * r << endl;
	}
};
template<class type>
class arry {
private:
	type n;
	type* num;
public:
	arry(type *num1,type n1)
	{
		num = num1;
		n = n1;
	}
	void show();
};
template<class type>
void arry<type>::show()
{
	for (type i = 0; i < n; i++)
	{
		cout << num[i] << endl;
	}
}
void main()
{
	int num[5] = { 4,3,4,3,1 };
	arry <int>arr1(num, 5);
	arr1.show();
	arr1.show();
}