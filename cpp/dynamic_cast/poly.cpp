#include <stdio.h>
#include <vector>

class X
{
	public:
		virtual void f(){printf("X\n");}
		void xa(){printf("X::xa\n");}
};

class A: public X
{
	public:
		virtual void f(){printf("A\n");}
		void fa(){printf("A::fa\n");}
};



int main()
{
	X x;
	A a;
	X* px = &a;
	if (A* pa = dynamic_cast<A*>(px))
	{
		printf("dynmaic_cast ok\n");
		pa->fa();
	}
	else
	{
		printf("dynamic_cast failed\n");
		px->xa();
	}
	return 0;

}
