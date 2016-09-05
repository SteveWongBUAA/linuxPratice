#include <string.h>
#include <stdio.h>

void funPointer(int num, char (*a)[20])
{
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", a[i]);
	}
}

void funArray(int num, char *a[])
{
	printf("%c\n", **a);
}

int main()
{
	char a[5][20];
	strcpy(a[0], "192.168.1.1");
	strcpy(a[1], "192.168.1.254");
	funPointer(2, a);
	funArray(2, a);
}
