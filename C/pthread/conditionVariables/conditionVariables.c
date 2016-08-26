#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void* funcCnt1();
void* funcCnt2();
int count = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main()
{
	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, funcCnt1, NULL);
	pthread_create(&thread2, NULL, funcCnt2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count: %d\n", count);

	exit(EXIT_SUCCESS);
}

void* funcCnt1()
{
	while (1)
	{
		pthread_mutex_lock(&count_mutex);
		printf("fun1 waiting\n");
		pthread_cond_wait(&condition_var, &count_mutex);
		count++;
		printf("Counter value funcCnt1: %d\n", count);
		pthread_mutex_unlock(&count_mutex);
		if(count >= COUNT_DONE)
			return NULL;
	}
}

void* funcCnt2()
{
	while (1)
	{
		pthread_mutex_lock(&count_mutex);
		
		if (count < COUNT_HALT1 || count > COUNT_HALT2)
		{
			printf("fun2 sent signal to fun1\n");
			pthread_cond_signal(&condition_var);
		}
		else
		{
			count++;
			printf("Counter value funcCnt2: %d\n", count);
		}

		pthread_mutex_unlock(&count_mutex);

		if (count >= COUNT_DONE)
			return NULL;
	}
}
