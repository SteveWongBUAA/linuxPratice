#include <iostream>
#include <stdlib.h>
using namespace std;

void shuffle(int a[], int n)
{
	if (n < 1)
		return;
	swap(a[n-1], a[rand()%n]);
	shuffle(a, n-1);
}

void pv(int a[], int len)
{
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[52];
	for (int i = 1; i <= 52; i++)
		a[i-1] = i;
	pv(a, 52);
	shuffle(a, 52);
	pv(a, 52);

}
