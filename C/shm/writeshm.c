#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 1024
#define MYKEY 24
int main()
{
	int shmid;
	char *shmptr;
	if ((shmid = shmget(MYKEY, BUF_SIZE, IPC_CREAT)) == -1)
	{
		printf("shmget error\n");
		exit(1);
	}
	printf("shmid = %d\n", shmid);
	if ((shmptr = shmat(shmid, 0, 0)) == (void*)-1)
	{
		printf("shmat error\n");
		exit(1);
	}
	printf("origin shmptr = %p\n", shmptr);
	while(1)
	{
		scanf("%s", shmptr);
		//printf("shmptr addr = %p, shmptr = %s\n", shmptr, shmptr);
		//sleep(3);
	}
	exit(0);
	



}

