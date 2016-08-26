#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void *ptr);
void *cal(void *ptr);
void cal1(int);

int main()
{
	pthread_t thread1, thread2, thread3;
	const char *message1 = "Thread1";
	int cnt = 10;
	int *pcnt = &cnt;
	int iret1, iret2, iret3;
	iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
	if (iret1)
	{
		fprintf(stderr, "Error - pthread_create() return code: %d\n", iret1);
		exit(EXIT_FAILURE);
	}
	iret2 = pthread_create(&thread2, NULL, cal, (void*) pcnt);
	if (iret2)
	{
		fprintf(stderr, "Error - pthread_create() return code: %d\n", iret2);
		exit(EXIT_FAILURE);
	}
	iret3 = pthread_create(&thread3, NULL, cal1, cnt);
	if (iret3)
	{
		fprintf(stderr, "Error - pthread_create() return code: %d\n", iret3);
		exit(EXIT_FAILURE);
	}

	printf("pthread_create() for thread1 returns: %d\n", iret1);
	printf("pthread_create() for thread2 returns: %d\n", iret2);
	printf("pthread_create() for thread3 returns: %d\n", iret3);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	exit(EXIT_SUCCESS);

	return 0;

}

void *print_message_function(void *ptr)
{
	char *message;
	message = (char*) ptr;
	printf("%s \n", message);
}

void *cal(void *ptr)
{
	int *pcnt = (int*)ptr;
	int cnt = *pcnt;
	while (cnt--)
	{
		printf("cal1 %d\n", cnt);
		sleep(1);
	}
	return ptr;
}

void cal1(int cnt)
{
	while (cnt--)
	{
		printf("cal2 %d\n", cnt);
		sleep(1);
	}
}
