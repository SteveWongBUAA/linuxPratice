#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void myHandler(int sig);

int main()
{
	struct sigaction act, oact;
	act.sa_handler=myHandler;//设置信号捕获函数
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGUSR1, &act, &oact);
	long long i = 0;
	while(1)
	{
		i++;
		if (i % 100000000 == 0)
			printf("%lld\n", i);
		//printf("hello world\n");
		//pause();
	}
}

void myHandler(int sig)
{
	printf("i got signal: %d.\n", sig);
}
