//PLOBLEM
//http://www.nowcoder.com/questionTerminal/3d6043bf4c45410ab65fe4486f7fd7c4
#include <iostream>
#include <string>
#include <list>
using namespace std;

const int CNTNUM = 2; 

int link(const int num)
{
	list<int> l;
	for (int i = 1; i <= num; i++)
		l.push_back(i);
	auto iter = l.begin();
	while (l.size() > 1)
	{
		for (int i = 1; i < CNTNUM; i++)
		{
			if (++iter == l.end())
				iter = l.begin();
		}
		cout << *iter << endl;
		auto tmp = iter;
		if (++tmp == l.end())
			tmp = l.begin();
		l.erase(iter);
		iter = tmp;
	}
	return *l.begin();
}

int mathsolve(const int num)
{
	if (num == 0 || num == 1)
		return 0;
	int res = 0;
	for (int i = 2; i <= num; i++)
	{
		res = (res + CNTNUM) % i;
		//cout << res << endl;
	}
	return res;
}


int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "00e0")
			return 0;
		int num = (s[0] - '0');
		num = num * 10 + int(s[1] - '0');
		for (int i = 0; i < int(s[3] - '0'); i++)
			num *= 10;
		//cout << num << endl;
		//int res = link(num);
		//cout << "res\n";
		//cout << res << endl;
		//cout << "res2\n";
		cout << mathsolve(num) + 1 << endl;
	}
	return 0;
}

