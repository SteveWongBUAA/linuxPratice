#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		p = NULL;
		cout<<"A()\n";
	}
	A(int i)
	{
		p = new int;
		*p = i;
		cout<<"A(int i)\n*p= " << *p << endl;
	}
	int *p;
private:
	int m_data;
};

int main()
{
	A a(2), b[3], *p[4];
	*a.p = 5;
	cout << *(a.p) << endl;
	return 0;
}

