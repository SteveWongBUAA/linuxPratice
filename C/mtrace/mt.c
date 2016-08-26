#include <stdlib.h>
#include <mcheck.h>
int main()
{
	mtrace();
	int *a;
	a = malloc(sizeof(int));
	muntrace();
	return 0;
}
