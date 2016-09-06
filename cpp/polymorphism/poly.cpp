#include <stdio.h>
#include <vector>

class X
{
	public:
		virtual void f(){printf("X");}
};

class A: public X
{
	public:
		virtual void f()
		{

			printf("A");
		}
};

class B: public X
{
	public:
		virtual void f(){printf("B");}
};

class D: public A
{
	public:
		void f(){printf("D");}
};

class E: public B
{
	public:
		virtual void f(){printf("E");}
};

void print(X* x)
{
	x->f();
	x->X::f();
}


int main()
{
	std::vector<void*> vec;
	//std::vector<B*> vec;
	vec.push_back(new D);
	vec.push_back(new A);
	vec.push_back(new X);
	vec.push_back(new B);
	vec.push_back(new E);

	for (std::vector<void*>::size_type i = 0; i < vec.size(); ++i)
	{
		static_cast<D*>(vec[i])->f();
		//(vec[i])->f();
	}

	printf("\n");

	print(new D);
	print(new A);
	print(new X);
	print(new B);
	print(new E);
	

	return 0;

}
