#include <stdlib.h>
#include <new>
#include <mcheck.h>
#include <iostream>
using namespace std;

class C
{
public:
	C()
	{
		cout << "new " << this << endl;
	}
	~C()
	{
		cout << "delete " << this << endl;
	}
};

int main()
{
	mtrace();
	C *pc;
	pc = new C[10];
	delete []pc;
	muntrace();
	return 0;
}
