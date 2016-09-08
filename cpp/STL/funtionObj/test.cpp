#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

#define VSIZE 24

vector<long> v(VSIZE);

void initialize(long &ri);
void show(const long &ri);
bool isMinus(const long &ri);


int main()
{
	srandom(time(NULL));

	for_each(v.begin(), v.end(), initialize);
	cout << "vector of signed long intergers" << endl;
	for_each(v.begin(), v.end(), show);
	cout << endl;
	
	int count = 0;
	vector<long>::iterator p;
	p = find_if(v.begin(), v.end(), isMinus);
	while (p != v.end())
	{
		count++;
		p = find_if(p+1, v.end(), isMinus);
	}
	cout << "number of values: " << VSIZE << endl;
	cout << "negative values: " << count << endl;
	return 0;
}

void initialize(long &ri)
{
	ri = random() - RAND_MAX / 2;
}


void show(const long &ri)
{
	cout << ri << " ";
}

bool isMinus(const long &ri)
{
	return (ri < 0);
}
