#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

class A
{
public:
	A()
	{
		p = new int;
		cout<< this <<" A()\n";
		cnt++;
		cout << "cnt = " << cnt << endl;
	}
	A(int i)
	{
		p = new int;
		*p = i;
		cout << this << " A(int i) *p= " << *p << endl;
		cnt++;
		cout << "cnt = " << cnt << endl;
	}
	int *p;
	static int cnt;

	A(const A& a)
	{
		p = new int;
		*p = *(a.p);
		cout << this << " " << &a  << " copy A\n";
		cnt++;
		cout << "cnt = " << cnt << endl;
	}


	~A()
	{
		if (p != NULL)
		{
			delete p;
			p = NULL;
		}
		cnt--;
		cout << this << " ~A() cnt = " << cnt << endl;
	}

private:
	int m_data;
};

int A::cnt;

int main()
{
	//A a(2), b[3], *p[4];
	A a;
	*a.p = 5;
	cout << *(a.p) << endl;
	cout << "vector\n";
	vector<A> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(a);
		cout << "# " << i << " " << &(v[i]) << " "  << *(v[i].p) << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "# " << i << " " << &(v[i]) << " "  << *(v[i].p) << endl;
	}
	//cout << &(v[1]) << " "  << *(v[1].p) << endl;

	return 0;
}

