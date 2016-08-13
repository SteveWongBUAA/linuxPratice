#include <stdlib.h>
#include <mcheck.h>
int main()
{
	mtrace();
	int *a;
	a = malloc(sizeof(int));
	if (a == NULL)
		return 1;
	free(a);
	muntrace();
	return 0;
}
