#include <iostream>
using namespace std;

int main()
{
	union
	{
		struct
		{
			int a;
			char key[5];
		};
		char d[10];
	}u;

	cout << sizeof(u) << endl;


	return 0;
}
