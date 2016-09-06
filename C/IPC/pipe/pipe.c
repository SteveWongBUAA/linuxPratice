#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 8000

int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char linep[MAXLINE];
	char linec[MAXLINE];

	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid > 0)// parent, write
	{
		close(fd[0]);
		for (int i = 0; ; i++)
		{
			int res = write(fd[1], "hello child 11111111", 20);
			printf("%d th write res: %d\n",i, res);
		}
		close(fd[1]);
		//read(fd[0], linep, MAXLINE);
		//printf("now the parent read: %s\n", linep);
		wait(NULL);

	}
	else// child, read
	{
		close(fd[1]);
		printf("child blocked, waiting..\n");
		sleep(5);
		while (1)
		{
			int res0 = read(fd[0], linec, MAXLINE);
			printf("# read res0 = %d, now the child read: %s\n", res0, linec);
			sleep(1);
		}
	}
	return 0;
}
