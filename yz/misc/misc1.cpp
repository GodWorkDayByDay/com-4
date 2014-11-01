#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef int (*pFunc)(int, int);

int add(int a, int b)
{
	return a+b;
}

class Subtract
{
public:
	int operator()(int a, int b)
	{
		return a-b;
	}
};

class Test
{
public:
	Test() : m_a(), m_b() { }
	void fun()
	{
		cout << "Test::fun()." << endl;
	}

private:
	int m_a;
	int m_b;
};

template <class T>
class Wrapter
{
public:
	Wrapter(T *pi) : _ptr(pi) { }
	T* operator->()
	{
		return _ptr;
	}

private:
	T *_ptr;
};

template<typename Func>
class FunObj
{
public:
	FunObj(const Func &funObj = Func()) : m_funObj(funObj) { }
	void func() { m_funObj(1, 2); }

private:
	Func m_funObj;
};

bool abc(int, int)
{
	return true;
}

class Y
{
public:
	Y() { cout << "in Y." << endl; }
	void *operator new(size_t sz)
	{
		cout << "in operator new." << " size: " << sz <<endl;
		return ::operator new(sz);
	}
	virtual void func() { cout << "in Y.func" << endl; }

public:
	int m_val;
};

class Z : public Y
{
public:
	Z() { cout << "in Z." << endl; }
	void func() { cout << "in Z.func" << endl; }
public:
	int m_arr[3];
};

void _memcpy(void *dst, void *src, size_t sz)
{
	char *_dst = (char *)dst;
	char *_src = (char *)src;
	while (sz--)
	{
		*_dst++ = *_src++;
	}
}

class YY
{
public:
	YY() { }
private:
	int m_c;

protected:
	int m_e;

public:
	int m_d;

	static int a;
	static int b;
};

int YY::a = 1;
int YY::b = 2;

int main()
{
	FunObj<pFunc> f(add);
	f.func();

	Subtract a;
	cout << a(1, 2) << endl;

	Wrapter<Test> wt(new Test);
	wt->fun();

	void *p = ::operator new(10);


	int iArr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9, 10 };
	int *pi = upper_bound(iArr, iArr+sizeof(iArr)/sizeof(int), 6, abc);
	cout << pi-iArr << endl;

	cout << "//////////////////////////////////////////////////////" << endl;
	Y *py = new Z;
	Z *pz = new Z;
	py->func();
	pz->func();

	Z z;
	z.m_val = 1;
	z.m_arr[0] = 2;
	z.m_arr[1] = 3;
	z.m_arr[2] = 4;

	Z zz;
	_memcpy(&zz, &z, sizeof(Z));

	char str1[] = "fuck";
	char str2[] = "fucker";

	cout << strcmp(str1, str2) << endl;

	YY yy;

	return 0;
}
