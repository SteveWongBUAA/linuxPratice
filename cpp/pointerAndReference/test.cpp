#include <iostream>
using namespace std;

int main()
{
	int a, &ra = a, *refp = &ra;
	int *pi, *&pref=pi;
	cout << &pi << ' ' << &pref << endl;
	return 0;
}

