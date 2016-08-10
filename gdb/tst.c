#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int func(int n)
{
	int sum = 0,i;
	for (i = 0; i < n;i++)
		sum+=i;
	return sum;
}

int main()
{
	int i;
	long result = 0;
	vector<int> v;
	for (i = 1; i <= 100; i++)
	{
		result  += i;
		v.push_back(i);
	}

	printf("result[1-100] = %d/n", result);
	printf("result[1-100] = %d/n", func(250));

}
