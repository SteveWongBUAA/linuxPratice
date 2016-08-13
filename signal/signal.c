#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_usr(int sig);

int main()
{
	int i = 0;
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can not catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can not catch SIGUSR2\n");
	while(1)
	{
		printf("%2d\n", i);
		pause();
		i++;

	}
	return 0;
}

void sig_usr(int sig)
{
	if (sig == SIGUSR1)
		printf("receive SIGUSR1\n");
	else if (sig == SIGUSR2)
		printf("receive SIGUSR2\n");
	else
		printf("undeclared signal %d\n", sig);
}
