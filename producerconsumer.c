#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


pthread_mutex_t mutex;
pthread_t p, c;
sem_t full, empty;
int counter = 0, buffer[10] = {0};


void * producer(void * param)
{
	int i;


	sem_wait(&empty);

	pthread_mutex_lock(&mutex);

	printf("Producer produces\n");

	buffer[counter++] = 1;

	printf("Buffer:\n");

	for(i=0; i<10; i++)
		printf("%d\t", buffer[i]);
	printf("\n");
	

	pthread_mutex_unlock(&mutex);
	
	sem_post(&full);
}

void * consumer(void * param)
{
	int i;

	sem_wait(&full);

	pthread_mutex_lock(&mutex);

	buffer[--counter] = 0;
	printf("Consumer consumes\n");

	printf("Buffer:\n");

	for(i=0; i<10; i++)
		printf("%d\t", buffer[i]);
	printf("\n");

	pthread_mutex_unlock(&mutex);

	sem_post(&empty);
}


int main()
{
	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 1, 0);
	sem_init(&empty, 1, 10);


	pthread_create(&p, NULL, producer, NULL);
	pthread_create(&p, NULL, producer, NULL);


	pthread_create(&c, NULL, consumer, NULL);
	pthread_create(&c, NULL, consumer, NULL);


	pthread_join(p, NULL);
	pthread_join(p, NULL);


	pthread_join(c, NULL);
	pthread_join(c, NULL);



	printf("\n");
	return 0;
}