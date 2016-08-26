#include<iostream>
#include"coordin.h"
using namespace std;
int main()
{
	rect rplace;
	polar pplace;

	cout << "enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "next two numbers (q to quit):";
	}
	cout << "Bye!\n" ;
	return 0;
}
