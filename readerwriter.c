#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

int rcounter = 0;

pthread_mutex_t mutex, wrt;
pthread_t w, r;

void * reader(void * params)
{
	pthread_mutex_lock(&mutex);
	rcounter++;

	if(rcounter == 1)
		pthread_mutex_lock(&wrt);

	pthread_mutex_unlock(&mutex);

	printf("Reading %d Reading\n", rcounter);

	pthread_mutex_lock(&mutex);
	rcounter--;

	if(rcounter == 0)
		pthread_mutex_unlock(&wrt);

	pthread_mutex_unlock(&mutex);

}

void * writer(void * params)
{

	pthread_mutex_lock(&wrt);

	printf("Writer Writes\n");

	pthread_mutex_unlock(&wrt);
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&wrt, NULL);

	pthread_create(&r, NULL, reader, NULL);
	pthread_create(&r, NULL, reader, NULL);

	pthread_create(&w, NULL, writer, NULL);

	pthread_join(r, NULL);
	pthread_join(r, NULL);

	pthread_join(w, NULL);


	printf("\n");
	return 0;
}