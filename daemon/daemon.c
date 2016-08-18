#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

#define ERR_EXIT(m) \
	do \
{\
	perror(m);\
	exit(EXIT_FAILURE);\
}\
while(0);\

void creat_daemon(void);

int main()
{
	time_t t;
	int fd;
	if (daemon(0, 0) == -1)
		ERR_EXIT("daemon error");	
	while (1)
	{
		fd = open("daemon.log", O_WRONLY|O_CREAT|O_APPEND, 0644);
		if(fd == -1)
			ERR_EXIT("open error");
		t = time(0);
		char *buf = asctime(localtime(&t));
		write(fd, buf, strlen(buf));
		close(fd);
		sleep(60);
	}
	return 0;
}

void creat_daemon()
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");
	if (pid > 0)
		exit(EXIT_SUCCESS);
	if (setsid() == -1)
		ERR_EXIT("SETSID ERROR");
	chdir("/");
	int i;
	for (i = 0; i < 3; i++)
	{
		close(i);
		open("/dev/null", O_RDWR);
		dup(0);
		dup(0);
	}
	umask(0);
	return;


}
