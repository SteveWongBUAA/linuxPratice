// PROBLEM:
// http://www.nowcoder.com/questionTerminal/876e3c5fcfa5469f8376370d5de87c06
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

void solve(vector<int> v, set<int> &s, const int &sum, const int i, const int len)
{
	if (i == len)
	{
		if (s.find(sum) == s.end())
			s.insert(sum);
		return;
	}
	solve(v, s, sum, i+1, len);
	solve(v, s, sum+v[i], i+1, len);
}

int solve2(vector<int> v)
{
	sort(v.begin(), v.end());
	//for (auto i: v)
	//	cout << i << ' ';
	//cout << endl;
	int N = 0;
	for (auto x : v)
	{
		if (x <= N+1)
			N += x;
		else
			break;
	}
	return N+1; 
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
		// solve1
		//set<int> s;
		//int sum = 0;
		//solve(v, s, sum, 0, n);
		//for (auto i : s)
		//	cout << i << ' ';
		//cout << endl;
		//int res = 0;
		//for (int i = 0; i < INT_MAX; i++)
		//{	
		//	if (s.find(i) == s.end())
		//	{
		//		cout << i << endl;
		//		break;
		//	}
		//}
		//
		// solve2
		cout << solve2(v) << endl;
	}
	return 0;
}


