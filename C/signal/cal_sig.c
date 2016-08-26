#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
long long count = 0;//计数值
const long long LIMIT = 0x0ffffffff;
void sig_usr(int sig);//处理普通信号SIGUSR1

int main(int argc, char *argv[])
{
	printf("long long max = %lld\n", LIMIT);
	pid_t pid;
	pid_t ppid = getpid();
	printf("before fork pid = %d\n", getpid());
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)//子进程,负责计数
	{
		printf("child process: %d\n", getpid());
		signal(SIGUSR1, sig_usr);//注册信号,收到信号就打印当前进度
		while(count <= LIMIT)
			count+=3;
		kill(ppid, SIGKILL);
	}
	else//父进程,负责定时读子进程的进度
	{
		printf("parent process pid : %d\n", getpid());
		while (1)
		{
			sleep(1);
			printf("parent is going to send siginal to child %d\n", pid);
			kill(pid, SIGUSR1);
		}
	}
	return 0;
}


void sig_usr(int sig)
{
	float per;
	per = (float)count/(float)LIMIT;
	printf("current count = %lld, percentage =  %.6f%%\n", count, per*100);
}

