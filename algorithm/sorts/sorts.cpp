#include <iostream>
using namespace std;

void myprint(const int *a, const int start, const int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void descBubbleSort(int *a, const int start, const int end)
{
	for (int i = start; i <= end; i++)
	{
		for (int j = start + 1; j <= end; j++)
		{
			if (a[j-1] < a[j])
				swap(a[j-1], a[j]);
		}
	}
}

void ascBubbleSort(int *a, const int start, const int end)
{
	for (int i = start; i <= end; i++)
	{
		for (int j = start + 1; j <= end; j++)
		{
			if (a[j-1] > a[j])
				swap(a[j-1], a[j]);
		}
	}
}

void descSelSort(int* a, int start, int end, bool isdesc)
{
	for (int i = start; i <= end; i++)
	{
		int index = i;
		for (int j = i + 1; j <= end; j++)
		{
			if (isdesc)
			{
				if (a[index] < a[j])
					index = j;
			}
			else
			{
				if (a[index] > a[j])
					index = j;
			}
		}
		swap(a[index], a[i]);
	}
}

int descpartition(int* a, int start, int end, bool isdesc)
{
	int lo = start;
	int hi = start;
	while (hi < end)
	{
		if (isdesc)
		{
			if (a[hi] < a[end])
				swap(a[lo++], a[hi++]);
			else
				hi++;
		}
		else
		{
			if (a[hi] > a[end])
				swap(a[lo++], a[hi++]);
			else
				hi++;
		}
	}
	swap(a[lo], a[end]);
	return lo;
}

void descquickSort(int* a, int start, int end, bool isdesc)
{
	if (start >= end)
		return;
	int p = descpartition(a, start, end, isdesc);
	descquickSort(a, start, p-1, isdesc);
	descquickSort(a, p+1, end, isdesc);
}

void descinsSort(int* a, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j > start; j--)
		{
			if (a[j] > a[j-1])
				swap(a[j], a[j-1]);
			else
				break;
			
		}
	}  
}

void ascinsSort(int* a, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j > start; j--)
		{
			if (a[j] < a[j-1])
				swap(a[j], a[j-1]);
			else
				break;
			
		}
	}  
}

void mysort(int* a, const int N, const int k)
{
	//ascBubbleSort(a, 0, k);
	//descBubbleSort(a, k+1, N-1);
	//descquickSort(a, 0, k, 1);
	//descquickSort(a, k+1, N-1, 0);
	ascinsSort(a, 0, k);
	descinsSort(a, k+1, N-1);
	
}





int main()
{
	int a[8] = {3,4,2,1,5,6,8,7};
	myprint(a, 0, 7);
	mysort(a, 8, 2);
	myprint(a, 0, 7);

	return 0;
}


