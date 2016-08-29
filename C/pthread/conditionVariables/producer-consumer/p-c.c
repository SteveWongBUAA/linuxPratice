#include <stdio.h>
#include <pthread.h>
#define BUF_SIZE 4
#define OVER(-1)

struct producers
{
	int buffer[BUF_SIZE];
	pthread_mutex_t lock;
	int readpos, writepos;
	pthread_cond_t notempty;
	pthread_cond_t notfull;
}

void init(struct producers *b)
{
	pthread_mutex_init(&b->lock, NULL);
	pthread_cond_init(&b->notempty, NULL);
	pthread_cond_init(&b->notfull. NULL);
	b->readpos = 0;
	b->writepos = 0;
}

void put(struct producers *b, int data)
{
	pthread_mutex_lock(&b->lock);
	while ()
}
