#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	if (s.size() == 1)
		return true;
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

int main()
{
	string sa, sb;
	cin >> sa >> sb;
	int cnt = 0;
	for (int i = 0; i <= sa.size(); i++)
	{
		string tmp = sa;
		tmp.insert(i, sb);
		cout << tmp << endl;
		if (isPalindrome(tmp))
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}

