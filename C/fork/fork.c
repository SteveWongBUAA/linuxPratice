#include<stdio.h>
#include<unistd.h>


int glo = 0;
int main()
{
	pid_t pid;
	printf("init glo = %d\n", glo);
	pid = fork();
	if (pid < 0)
	{
		printf("fork error!");
		return -1;
	}
	else if (pid == 0)//child
	{
		printf("# i am child and now glo = %d\n", glo);
		for (int i = 0; i < 5; i++)
		{
			sleep(1);
			printf("# i am child and now ++glo, glo = %d\n", ++glo);
		}

		

	}
	else //parent
	{
		printf("i am the parent and my child = %d, and now glo = %d\n", pid, glo);
		for (int i = 0; i < 5; i++)
		{
			sleep(3);
			printf("i am parent and now --glo, glo = %d\n", --glo);
		}

	}

	
	return 0;
}
