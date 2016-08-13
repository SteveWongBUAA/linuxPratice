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
	pc = new C[5];
	//int *a;
	//a = new int[10];
	//delete a;
	cout << "addr of pc: " << pc << endl;
	cout << "size of pc: " << sizeof(pc) << endl;
	cout << "size of class C: "<< sizeof(C) << ", " << sizeof(pc[0]) << endl;
	delete pc;
	muntrace();
	return 0;
}
