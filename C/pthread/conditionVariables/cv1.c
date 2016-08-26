// reference http://casatwy.com/pthreadde-ge-chong-tong-bu-ji-zhi.html
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void* pre();
void* waitforpre();
int done = 0;


int main()
{
	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, waitforpre, NULL);

	//sleep(2);

	
	pthread_create(&thread2, NULL, pre, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


	exit(EXIT_SUCCESS);
}

// we just want to make sure that some jobs in waitforpre() will start after the pre() is done.
void* waitforpre()
{
	pthread_mutex_lock(&count_mutex);
	// if not prepare jobs are not done, we should wait
	while (done == 0)
	{
		printf("now function waitforpre is waiting...\n");
		pthread_cond_wait(&condition_var, &count_mutex);
	}

	printf("in function wait for pre, now done = %d\n ", done);
	pthread_mutex_unlock(&count_mutex);
}

void* pre()
{
	pthread_mutex_lock(&count_mutex);

	printf("in function pre, doing some prepare works.\n");
	sleep(1);

	done = 1;
	
	printf("prepare work done, now fun2 sends signal \n");
	pthread_cond_signal(&condition_var);

	pthread_mutex_unlock(&count_mutex);

}
