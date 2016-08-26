#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define BUF_SIZE 1024
#define MYKEY 24
int main()
{
	int shmid;
	long long *shmptr;
	if ((shmid=shmget(MYKEY, BUF_SIZE, IPC_CREAT)) == -1)
	{
		printf("shmget error\n");
		exit(1);
	}
	printf("shmid = %d\n", shmid);
	if ((shmptr = shmat(shmid, 0, 0)) == (void*)-1)
	{
		printf("shmat error\n");
	}
	while (1)
	{
		printf("num:%lld\n", *shmptr);
		sleep(3);
	}
	exit(0);

}
