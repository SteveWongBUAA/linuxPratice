#include <iostream>
#include <vector>
using namespace std;

void rmEven(vector<int>& v)
{
	auto i = v.begin();
	while(i != v.end())
	{
		cout << "now is " << *i << endl;
		if (((*i) & 0x01) == 0)
		{
			cout << "rm " << *i << endl;
			i = v.erase(i);
		}
		else
			++i;
	}
}

void printv(vector<int> v)
{
	for (auto i: v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v = {0,1,2,3,4,5,6,7,8};
	printv(v);
	rmEven(v);
	printv(v);
	
	return 0;
}

