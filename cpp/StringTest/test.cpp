#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string s = "asd";
	cout << s << " " << s.length() << endl;
	char *tmp = "asd";
	cout << tmp << " " << strlen(tmp) << endl;
	return 0;
}

