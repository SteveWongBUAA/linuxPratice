#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
int count;//当前复制大小
int file_size;//文件大小，因在终端无法传递普通参数，故用全局变量
void sig_alarm(int arg);
void sig_usr(int sig);//处理普通信号SIGUSR1

int main(int argc, char *argv[])
{
	pid_t pid;
	int i;
	int fd_src, fd_des;
	char buff[128];
	count = 0;
	if (argc!=3)
	{
		printf("check the format: comn src_file des_file\n");
		return -1;
	}
	if ((fd_src=open(argv[1], O_RDONLY))==-1)
	{
		perror("open file src");
		exit(EXIT_FAILURE);
	}
	file_size = lseek(fd_src, 0, SEEK_END);
	lseek(fd_src, 0, SEEK_SET);
	if ((fd_des=open(argv[2], O_RDWR|O_CREAT, 0644)) == -1)
	{
		perror("open fd_des");
		exit(EXIT_FAILURE);
	}
	printf("before fork pid = %d\n", getpid());
	pid = fork();
	if (pid < 0)
	{
		printf("error in fork!\n");
		perror("fork");
	}
	else if (pid == 0)//子进程,负责写文件
	{
		printf("child process: %d\n", getpid());
		signal(SIGUSR1, sig_usr);//注册信号,收到信号就打印当前进度
		do
		{
			memset(buff, '\0', 128);
			if ((i=read(fd_src, buff, 1)) == -1)
			{
				perror("read");
				exit(EXIT_FAILURE);
			}
			else if(i == 0)
			{
				printf("i am going to kill myself! pid = %d\n", pid);
				kill(pid, SIGINT);
				break;
			}
			else
			{
				if (write(fd_des, buff, i) == -1)
				{
					perror("write");
					exit(EXIT_FAILURE);
				}
				count+=i;
			}
			sleep(1);
		}
		while(i!=0);
		//waitpid(pid, NULL, 0);//等待子进程退出
		//exit(EXIT_SUCCESS);
		
	}
	else//父进程,负责定时读子进程的进度
	{
		printf("parent process pid : %d\n", getpid());
		//signal(SIGALRM, sig_alarm);
		//ualarm(1,1);
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
	printf("count = %d, file_size = %d\n");
	per = (float)count/(float)file_size;
	printf("currnet write  : 0.0f%%\n", per*100);
}

