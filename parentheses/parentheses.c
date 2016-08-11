//PROBLEM
//generate parentheses

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(const string s, const int nleft, const int nright)
{
	if (nleft == 0 && nright == 0)
	{
		cout << s << endl;
		return;
	}
	if (nleft)
		solve(s+'(', nleft-1, nright);
	if (nright)
		solve(s+')', nleft, nright-1);

}
int main()
{
	string s = "";
	solve(s, 2, 2);
	return 0;
}
