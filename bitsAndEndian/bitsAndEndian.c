#include<stdio.h>

static union
{
	char c[4];
	unsigned long mylong;
}endian_test = {{'l', '?', '?', 'b'}};

#define ENDIANNESS ((char)endian_test.mylong)

int main()
{
	void* a = 0;
	printf("size of a ptr is %d\n", sizeof(a));
	printf("my os endian is %c\n", ENDIANNESS);
	return 0;
}
