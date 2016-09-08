#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int>& v, const char* s)
{
	cout << s << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	vector<int> v = {1,3,2,5,4};
	display(v, "before sort");
	sort(v.begin(), v.end());
	display(v, "after sort");

	return 0;
}

