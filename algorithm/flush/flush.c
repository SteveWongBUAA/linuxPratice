#include <stdio.h>
#include <stdlib.h>
/*
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* a, int start, int end)
{
	int lo = start;
	int hi = start;
	while (hi < end)
	{
		if (a[hi] < a[end])
			swap(&(a[hi++]), &(a[lo++]));
		else
			hi++;
	}
	swap(&(a[lo]), &(a[end]));
	return lo;
}

void qsort(int* a, int start, int end)
{
	if (start >= end)
		return;
	int p = partition(a, start, end);
	qsort(a, start, p-1);
	qsort(a, p+1, end);
}
*/
void p(int* a, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int isFlush(int* a, int len)
{
	qsort(a, 0, len-1);
	int zeros = 0;
	for (int i = 0; i < len; i++)
		if (a[i] == 0)
			zeros++;
	for (int i = 0; i < len - 1; i++)
	{
		if (a[i] != 0)
		{
			int gap = a[i+1] - a[i];
			if (gap - 1 > zeros || gap == 0)
				return -1;
			else
				zeros -= (gap - 1);
		}
	}
	return 1;
}

int main()
{
	int a[5] = {2,5,1,4,8};
	p(a, 5);
	printf("a : %d\n", isFlush(a, 5));
	int b[5] = {3, 7, 0, 5, 0};
	p(b, 5);
	printf("b : %d\n", isFlush(b, 5));
	int c[5] = {3, 4, 0, 4, 0};
	p(c, 5);
	printf("c : %d\n", isFlush(c, 5));
}
